#include <iostream>
using namespace std;
int findFirst(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    int first = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            first = mid;
            right = mid - 1;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return first;
}
int findLast(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    int last = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            last = mid;
            left = mid + 1; // move right
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return last;
}
vector<int> searchRange(vector<int> &nums, int target)
{
    return {findFirst(nums, target), findLast(nums, target)};
}
int main()
{
    vector<int> nums{5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = searchRange(nums, target);
    cout << "[ ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    cout << "]";
    return 0;
}