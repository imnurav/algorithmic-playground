#include <iostream>
using namespace std;
int minPairSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int left = 0;
    int right = nums.size() - 1;
    int maxMin = 0;
    while (left < right)
    {
        int sum = nums[left] + nums[right];
        maxMin = max(maxMin, sum);
        left++;
        right--;
    }
    return maxMin;
}
int main()
{
     vector<int> arr={3,5,2,3};
     cout<<minPairSum(arr);
    return 0;
}