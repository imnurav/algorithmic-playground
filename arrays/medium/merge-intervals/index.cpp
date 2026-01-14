#include <iostream>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.empty())
        return {};

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    merged.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] <= merged.back()[1])
        {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        }
        else
        {
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}
int main()
{
    vector<vector<int>> nums = {{1, 3}, {2, 4}, {5, 7}, {6, 8}};
    vector<vector<int>> result = merge(nums);
    cout << "Merged intervals are: ";
    for (const auto &interval : result)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    return 0;
}