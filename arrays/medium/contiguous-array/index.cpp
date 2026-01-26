#include <iostream>
using namespace std;
int findMaxLength(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    mp[0] = -1;
    int result = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += (nums[i] == 1) ? 1 : -1;
        if (mp.find(sum) != mp.end())
        {
            result = max(result, i - mp[sum]);
        }
        else
        {
            mp[sum] = i;
        }
    }
    return result;
}
int main()
{
    vector<int> nums = {0, 1, 0, 1};
    int result = findMaxLength(nums);
    cout << "Maximum Length of Contiguous Array: " << result;
    return 0;
}