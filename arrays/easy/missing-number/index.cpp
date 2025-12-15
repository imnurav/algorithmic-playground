#include <iostream>
using namespace std;
int findMissingNumber(vector<int> &arr)
{
    int n = arr.size();
    int sum = n * (n + 1) / 2;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
    }

    return sum - total;
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
    vector<int> arr = {3, 2, 1, 0};
    int missing_number = findMissingNumber(arr);
    cout << "Missing number is " << missing_number << endl;
    return 0;
}