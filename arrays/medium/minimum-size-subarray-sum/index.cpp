#include <iostream>
using namespace std;
int minSubArrayLen(int target, vector<int> &nums)
{
    int n = nums.size();
    int left = 0;
    long long sum = 0;
    int minLen = INT_MAX;
    for (int right = 0; right < n; right++)
    {
        sum += nums[right];
        while (sum >= target)
        {
            minLen = min(minLen, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }
    return (minLen == INT_MAX) ? 0 : minLen;
}
// Alternative approach using Prefix Sums and Binary Search O(n log n)
int minSubArrayLen2(int target, vector<int> &nums)
{
    int n = nums.size();
    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    int minLen = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        long long required = target + prefix[i];
        auto it = lower_bound(prefix.begin(), prefix.end(), required);

        if (it != prefix.end())
        {
            int j = it - prefix.begin();
            minLen = min(minLen, j - i);
        }
    }

    return (minLen == INT_MAX) ? 0 : minLen;
}
int main()
{
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    int result = minSubArrayLen(target, nums);
    cout << "Minimum Size Subarray Sum for Target " << target << ": " << result;
    return 0;
}