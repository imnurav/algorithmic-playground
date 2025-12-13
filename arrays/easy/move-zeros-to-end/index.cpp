#include <iostream>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int insertPos = 0;
    for (int num : nums)
    {
        if (num != 0)
        {
            nums[insertPos++] = num;
        }
    }
    while (insertPos < nums.size())
    {
        nums[insertPos++] = 0;
    }
}
int main()
{
    // int n;
    // cin >> n;
    // vector arr(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    vector<int> arr = {0, 1, 0, 3, 12};
    moveZeroes(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}