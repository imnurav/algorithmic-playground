#include <iostream>
using namespace std;
bool check(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 1)
        return true;
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
            count++;
    }
    if (nums[n - 1] > nums[0])
        count++;
    return count <= 1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bool isSortedRotated = check(arr);
    cout << boolalpha; // used for making 1 as True and 0 as False;
    cout << " Sorted And Rotated  " << isSortedRotated << endl;
    return 0;
}