#include <iostream>
using namespace std;
void sortColors(vector<int> &nums)
{
    int n = nums.size();
    int red = 0, white = 0, blue = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
            red++;
        else if (nums[i] == 1)
            white++;
        else
            blue++;
    }
    int i = 0;
    while (red > 0)
    {
        nums[i] = 0;
        i++;
        red--;
    }
    while (white > 0)
    {
        nums[i] = 1;
        i++;
        white--;
    }

    while (blue > 0)
    {
        nums[i] = 2;
        i++;
        blue--;
    }
}
int main()
{
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    sortColors(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}