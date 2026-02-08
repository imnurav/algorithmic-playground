#include <iostream>
using namespace std;
int dominantIndices(vector<int> &nums)
{
    int n = nums.size();
    long long suffixSum = 0;
    for (int i = 0; i < n; i++)
    {
        suffixSum += nums[i];
    }
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        suffixSum -= nums[i];
        int elementsRight = n - i - 1;
        if ((long long)nums[i] * elementsRight > suffixSum)
        {
            count++;
        }
    }
    return count;
}
int main()
{

    vector<int> nums = {5,4,3};
    cout << dominantIndices(nums) << endl;
    return 0;
}