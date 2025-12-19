#include <iostream>
using namespace std;
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> result;
    unordered_map<int, int> frequency;
    for (int num : nums1)
        frequency[num]++;
    for (int num : nums2)
    {
        if (frequency[num] > 0)
        {
            result.push_back(num);
            frequency[num] -= 1;
        }
    }
    return result;
}
int main()
{
    vector<int> arr1 = {1, 2, 2, 1};
    vector<int> arr2 = {2, 2};
    vector<int> result = intersect(arr1, arr2);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}