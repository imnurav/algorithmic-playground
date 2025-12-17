#include <iostream>
using namespace std;
int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> majority;
    for (int num : nums)
        majority[num]++;
    int elem = nums.size() / 2;
    for (auto x : majority)
    {
        if (x.second > elem)
            return x.first;
    }
    return 0;
}
int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "Majority Element is " << ans << endl;
    return 0;
}