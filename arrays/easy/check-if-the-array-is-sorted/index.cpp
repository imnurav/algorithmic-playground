#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // int arr[] = {1, 2, 2, 4, 5};
    // int n = sizeof(arr) / sizeof(arr[0]);

    bool isSorted = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            isSorted = false;
    }
    if (isSorted)
    {
        cout << "The array is sorted in non-decreasing order." << endl;
    }
    else
    {
        cout << "The array is not sorted in non-decreasing order." << endl;
    }
    return 0;
}