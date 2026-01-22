#include <iostream>
using namespace std;

int minPairSum(vector<int> &nums)
{
    int min = INT_MAX;
    int index = -1;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] + nums[i + 1] < min)
        {
            index = i;
            min = nums[i] + nums[i + 1];
        }
    }
    return index;
}
int minimumPairRemoval(vector<int> &nums)
{
    int count = 0;
    while (!is_sorted(nums.begin(), nums.end()))
    {
        int index = minPairSum(nums);
        nums[index] = nums[index] + nums[index + 1];
        nums.erase(nums.begin() + index + 1);
        count++;
    }
    return count;
}
int main()
{
    vector<int> nums = {5, 2, 3, 1};
    int result = minimumPairRemoval(nums);
    cout << result;
    return 0;
}