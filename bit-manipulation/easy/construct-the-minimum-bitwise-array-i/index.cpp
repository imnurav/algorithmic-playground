#include <iostream>
using namespace std;
vector<int> minBitwiseArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        bool isFound = false;
        for (int x = 0; x < nums[i]; x++)
        {
            if ((x | (x + 1)) == nums[i])
            {
                isFound = true;
                result.push_back(x);
                break;
            }
        }
        if (isFound == false)
        {
            result.push_back(-1);
        }
    }
    return result;
}
int main()
{
    vector<int> arr = {2, 3, 5, 7};
    vector<int> result = minBitwiseArray(arr);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}