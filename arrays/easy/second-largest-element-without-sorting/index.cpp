#include <iostream>
using namespace std;

int secondLargesElement(vector<int> &nums)
{
    int n = nums.size();
    int largest = -1, secondLargest = -1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > largest)
        {
            secondLargest = largest;
            largest = nums[i];
        }
        else if (nums[i] > secondLargest && nums[i] != largest)
        {
            secondLargest = nums[i];
        }
    }
    return secondLargest;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "Second Largest Element in this array is " << secondLargesElement(nums);
    return 0;
}