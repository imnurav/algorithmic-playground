#include <iostream>
using namespace std;
int longestSubArrayLength(vector<int> &arr, int k)
{
    unordered_map<int, int> mp;
    int sum = 0, maxLen = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            maxLen = i + 1;
        }
        if (mp.find(sum - k) != mp.end())
        {
            maxLen = max(maxLen, i - mp[sum - k]);
        }
        if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
    }
    return maxLen;
}
int main()
{
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k = 15;
    int length = longestSubArrayLength(arr, k);
    cout << "Longest Sub Array Length is " << length << endl;
    return 0;
}