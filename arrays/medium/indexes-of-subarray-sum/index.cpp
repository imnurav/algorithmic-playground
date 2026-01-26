#include <iostream>
using namespace std;
vector<int> subarraySum(vector<int> &arr, int target)
{
    int n = arr.size();
    long long sum = 0;
    int left = 0;
    for (int right = 0; right < n; right++)
    {
        sum += arr[right];
        while (sum > target && left <= right)
        {
            sum -= arr[left];
            left++;
        }

        if (sum == target)
            return {left + 1, right + 1};
    }
    return {-1};
}
int main()
{
    vector<int> arr = {1, 2, 3, 7, 5};
    int target = 12;
    vector<int> result = subarraySum(arr, target);
    cout << "Subarray Indices with Target Sum " << target << ": ";
    if (result.size() == 2)
        cout << "[" << result[0] << ", " << result[1] << "]";
    else
        cout << "[-1]";
    return 0;
}