#include <iostream>
using namespace std;
int minimumDifference(vector<int> &nums, int k)
{
    int n = nums.size();
    int minDiff = INT_MAX;
    sort(nums.begin(), nums.end());
    int i = 0;
    int j = k - 1;
    while (j < n)
    {
        int minEl = nums[i];
        int maxEl = nums[j];
        minDiff = min(minDiff, maxEl - minEl);
        i++;
        j++;
    }
    return minDiff;
}
int main()
{
    vector<int> nums = {90};
    int k = 1;
    cout << minimumDifference(nums, k) << endl;
    return 0;
}