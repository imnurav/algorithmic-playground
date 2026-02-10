#include <iostream>
#include <unordered_set>

using namespace std;
int longestBalanced(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        unordered_set<int> evenSet, oddSet;

        for (int j = i; j < n; j++)
        {
            if (nums[j] % 2 == 0)
                evenSet.insert(nums[j]);
            else
                oddSet.insert(nums[j]);

            if (evenSet.size() == oddSet.size())
            {
                ans = max(ans, j - i + 1);
            }
        }
    }

    return ans;
}
int main()
{

    vector<int> nums = {1, 2, 3, 2};
    int result = longestBalanced(nums);
    cout << result << endl;
    return 0;
}