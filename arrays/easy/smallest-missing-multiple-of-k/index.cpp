#include <iostream>
#include <unordered_set>
using namespace std;
int missingMultiple(vector<int> &nums, int k)
{
    unordered_set<int> s(nums.begin(), nums.end());
    for (int i = 1;; i++)
    {
        int multiple = i * k;
        if (s.find(multiple) == s.end())
        {
            return multiple;
        }
    }
}
int main()
{
    vector<int> nums = {8,2,3,4,6};
    int k = 2;
    cout << missingMultiple(nums, k) << endl; // Output: 5
    return 0;
}