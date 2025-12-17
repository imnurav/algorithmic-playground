#include <iostream>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++)
    {
        int left = target - nums[i];
        if (map.find(left) != map.end())
        {
            return {map[left], i};
        }
        map[nums[i]] = i;
    }
    return {};
}
int main()
{

    vector<int> arr = {2, 7, 11, 15};
    int target = 9;
    int n = arr.size();
    vector<int> res = twoSum(arr, target);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}