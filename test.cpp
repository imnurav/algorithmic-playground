#include <iostream>
#include <vector>
using namespace std;
// void contigiousSubArray(vector<int> &arr)
// {
//     vector<vector<int>> temp;
//     // [-8, 2, -10, 11, 22]
//     for (int i = 0; i < arr.size(); i++)
//     {
//         for (int right = i; right < arr.size(); right++)
//         {
//             int left = i;
//             cout << "[ ";
//             while (left <= right)
//             {
//                 cout << arr[left] << ((left < right) ? ", " : " ");
//                 left++;
//             }
//             cout << "]" << endl;
//         }
//         cout << endl;
//     }
// }

void maxSubarray(vector<int> arr)
{
    int res = arr[0], total = 0;
    int left = 0, right = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (total < 0)
        {
            total = 0;
            left = i;
            right = i;
        }
        total += arr[i];

        res = max(res, total);
        if (res > total)
        {
            right++;
        }
    }
    cout << "Maximum of Subarray is " << res << endl;

    cout << "Index Start from left = " << left << " and right = " << right << endl;
    cout << "[ ";
    for (int i = left; i <= right; i++)
    {
        cout << arr[i] << ((i < right) ? ", " : "");
    }
    cout << " ]";
}
int main()
{

    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // {-8, 2, -10, 11, 22};
    maxSubarray(arr);
    // contigiousSubArray(arr);

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << "[ ";
    //     for (int j = 0; j < subArr.size(); j++)
    //     {
    //         cout << subArr[i][j] << " ";
    //     }
    //     cout << " ]" << endl;
    // }

    return 0;
}