#include <iostream>
using namespace std;
int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    mp[0] = 1;
    int sum = 0;
    int count = 0;
    for (int num : nums)
    {
        sum += num;

        if (mp.find(sum - k) != mp.end())
        {
            count += mp[sum - k];
        }

        mp[sum]++;
    }
    return count;
}
int main()
{
    vector<int> nums = {1, 1, 1};
    int k = 2;
    int result = subarraySum(nums, k);
    cout << "Number of Subarrays with Sum " << k << ": " << result;
    return 0;
}