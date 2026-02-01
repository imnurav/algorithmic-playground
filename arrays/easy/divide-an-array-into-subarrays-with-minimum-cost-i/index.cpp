#include <iostream>
using namespace std;
int minimumCost(vector<int> &nums)
{
    int firstElement = nums[0];
    int smallest = 100;
    int secondSmallest = 100;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = nums[i];
        }
        else if (nums[i] < secondSmallest)
            secondSmallest = nums[i];
    }
    return firstElement + smallest + secondSmallest;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << minimumCost(nums) << endl;
    return 0;
}