#include <iostream>
using namespace std;
vector<int> minBitwiseArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result;

    for (int i = 0; i < n; i++)
    {

        if (nums[i] == 2)
        {
            result.push_back(-1);
            continue;
        }

        bool found = false;
        for (int j = 1; j < 32; j++)
        {
            if ((nums[i] & (1 << j)) > 0)
            {
                continue;
            }

            int prev = j - 1;
            int x = (nums[i] ^ (1 << (j - 1)));
            result.push_back(x);
            found = true;
            break;
        }
        if (found == false)
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