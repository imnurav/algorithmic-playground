#include <iostream>
using namespace std;
void backtrack(vector<int> &nums, vector<bool> &used, vector<int> &current,
               vector<vector<int>> &result)
{
    // If current permutation is complete
    if (current.size() == nums.size())
    {
        result.push_back(current);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (used[i])
            continue;

        // Choose
        used[i] = true;
        current.push_back(nums[i]);

        // Explore
        backtrack(nums, used, current, result);

        // Un-choose (Backtrack)
        current.pop_back();
        used[i] = false;
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(nums.size(), false);

    backtrack(nums, used, current, result);
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permute(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < result[0].size(); j++)
        {
            cout << result[i][j];
            if (j != result[i].size() - 1)
            {
                cout << " , ";
            }
        }
        cout << " ]" << endl;
    }

    return 0;
}