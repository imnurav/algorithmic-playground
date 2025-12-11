#include <iostream>
using namespace std;
int linearSearch(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
            return 1;
    }
    return -1;
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
    cout << "Enter the element to be searched: ";
    int target;
    cin >> target;
    int result = linearSearch(arr, target);
    cout << boolalpha;
    cout << " Element Found! " << bool(result) << endl;
    return 0;
}