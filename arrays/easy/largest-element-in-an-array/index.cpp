

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

    // int arr[] = {3, 5, 7, 2, 8, 8, 9, -1, 4};
    // int n = sizeof(arr) / sizeof(arr[0]);

    int largest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    cout << endl
         << "Largest Element In Array is " << largest << endl;
    return 0;
}