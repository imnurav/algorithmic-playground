#include <iostream>
using namespace std;

// Function to rotate the array by one place
// Time Complexity: O(n), Space Complexity: O(1)
void rotateArrayByOne(vector<int> &nums)
{
    // [1,2,3,4,5] -> [2,3,4,5,1]
    int firstElement = nums[0];
    for (int i = 0; i < nums.size() - 1; i++)
    {
        nums[i] = nums[i + 1];
    }
    nums[nums.size() - 1] = firstElement;
    cout << "Array after left rotation by one place: ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}

// Function to rotate the array by d places
// Time Complexity: O(n*d) => O(n^2), Space Complexity: O(1)
void rotateArrayByGivenPlaces(vector<int> &nums, int d)
{
    // [1,2,3,4,5] , d=2 -> [3,4,5,1,2]
    for (int i = 0; i < d; i++)
    {
        rotateArrayByOne(nums);
    }
}

// Alternative approach using a temporary buffer to rotate by d places
// Time Complexity: O(n), Space Complexity: O(n)
void rotateLeftByD_buffer(vector<int> &nums, int d)
{
    int n = nums.size();
    if (n == 0)
        return;

    d = d % n;

    if (d == 0)
        return;

    vector<int> tmp;
    tmp.reserve(n);

    // push elements from d to n-1
    for (int i = d; i < n; ++i)
        tmp.push_back(nums[i]);
    // then push elements from 0 to d-1
    for (int i = 0; i < d; ++i)
        tmp.push_back(nums[i]);

    // copy back
    for (int i = 0; i < n; ++i)
        nums[i] = tmp[i];
}

// Function to rotate the array to the right by k places
// Time Complexity: O(n), Space Complexity: O(n)
void rotateRightByK(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 0)
        return;

    k = k % n;

    if (k == 0)
        return;

    vector<int> tmp;
    tmp.reserve(n);

    for (int i = n - k; i < n; i++)
        tmp.push_back(nums[i]);

    for (int i = 0; i < n - k; i++)
        tmp.push_back(nums[i]);

    for (int i = 0; i < n; i++)
        nums[i] = tmp[i];
    cout << "Array after right rotation by " << k << " places: ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
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
    rotateArrayByOne(arr);
    return 0;
}