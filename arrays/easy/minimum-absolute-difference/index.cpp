#include <iostream>
using namespace std;
vector<vector<int>> minimumAbsDifference(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int minDiff = INT_MAX;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        minDiff = min(minDiff, arr[i + 1] - arr[i]);
    }
    vector<vector<int>> result;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] - arr[i] == minDiff)
        {
            result.push_back({arr[i], arr[i + 1]});
        }
    }
    return result;
}
int main()
{
    vector<int> arr = {4, 2, 1, 3};
    vector<vector<int>> result = minimumAbsDifference(arr);
    cout << "Minimum Absolute Difference Pairs: ";
    cout << "[";
    for (const auto &pair : result)
    {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << "]";
    return 0;
}