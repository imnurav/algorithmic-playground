#include <iostream>
#include <cmath>

using namespace std;

int maximumConsecutiveOnes(vector<int> &arr)
{
    int n = arr.size();
    int maxCount = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count++;
        }
        else
        {
            count = 0;
            maxCount = max(count, maxCount);
        }
    }
    maxCount = max(count, maxCount);
    return maxCount;
}

int main()
{
    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    vector<int> arr = {1, 1, 0, 0, 1, 1, 1, 1};
    cout << maximumConsecutiveOnes(arr);
    return 0;
}