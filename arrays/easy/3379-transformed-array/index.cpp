#include <iostream>
using namespace std;
vector<int> constructTransformedArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
            result[i] = 0;
        else
        {
            int targetIndex = (i + nums[i] % n + n) % n;
            result[i] = nums[targetIndex];
        }
    }
    return result;
}
int main()
{
    vector<int> nums = {3,-2,1,1};
    vector<int> result = constructTransformedArray(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}