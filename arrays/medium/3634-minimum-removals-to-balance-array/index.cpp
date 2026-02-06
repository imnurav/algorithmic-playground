#include <iostream>
using namespace std;

int minRemoval(vector<int> &nums, int k)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int left = 0, maxLength = 1;
    for (int right = 0; right < n; right++)
    {
        while ((long long)nums[right] > (long long)nums[left] * k)
        {
            left++;
        }
        maxLength = max(maxLength, right - left + 1);
    }
    return n - maxLength;
}
int main()
{
    vector<int> nums = {1, 6, 2, 9};
    int k = 3;
    int result = minRemoval(nums, k);
    cout << result << endl;
    return 0;
}