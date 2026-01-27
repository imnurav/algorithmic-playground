#include <iostream>
using namespace std;
vector<int> buildArray(vector<int> &nums)
{
    vector<int> ans(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++)
    {
        ans[i] = nums[nums[i]];
    }
    return ans;
}
// without extra space
/*
vector<int> buildArray(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        nums[i] = nums[i] + n * (nums[nums[i]] % n);
    }
    for (int i = 0; i < n; i++)
    {
        nums[i] = nums[i] / n;
    }
    return nums;
}
*/
int main()
{
    vector<int> nums = {0, 2, 1, 5, 3, 4};
    vector<int> result = buildArray(nums);
    cout << "Build Array from Permutation: ";
    cout << "[";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if (i != result.size() - 1)
            cout << ", ";
    }
    cout << "]";
    return 0;
}