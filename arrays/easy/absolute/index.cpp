#include <iostream>
using namespace std;
// int absDifference(vector<int> &nums, int k)
// {
//     sort(nums.begin(), nums.end());
//     int largest_total = 0;
//     int smallest_total = 0;
//     int n = nums.size();
//     for (int i = 0; i < k; i++)
//     {
//         smallest_total += nums[i];
//     }
//     // for (int i = n - 1; i >= n - k; i--)
//     // {
//     //     largest_total += nums[i];
//     // }
//     for (int i = nums.size() - 1; i >= nums.size() - k; i--)
//     {
//         largest_total += nums[i];
//     }
//     return abs(largest_total - smallest_total);
// }
int absDifference(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    long long largest_total = 0;
    long long smallest_total = 0;
    int n = nums.size();

    for (int i = 0; i < k; i++)
    {
        smallest_total += nums[i];
    }

    for (int i = n - k; i < n; i++)
    {
        largest_total += nums[i];
    }
    return abs(largest_total - smallest_total);
    // int n = nums.size();
    // if (k == 0 || k > n)
    //     return 0;
    // long long largest_total = 0;
    // long long smallest_total = 0;
    // nth_element(nums.begin(), nums.end() + k, nums.end());

    // for (int i = 0; i < k; i++)
    // {
    //     smallest_total += nums[i];
    // }
    // nth_element(nums.begin(), nums.end() - k, nums.end());

    // for (int i = n - k; i < n; i++)
    // {
    //     largest_total += nums[i];
    // }
    // return abs(largest_total - smallest_total);
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
    vector<int> arr = {5, 2, 2, 4};
    int k = 2;
    cout << absDifference(arr, k);
    return 0;
}