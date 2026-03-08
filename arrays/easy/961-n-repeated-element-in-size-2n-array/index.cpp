#include <iostream>
#include <unordered_set>
using namespace std;
int repeatedNTimes(vector<int> &nums)
{
    unordered_set<int> seen;

    for (int i : nums)
    {
        if (seen.count(i))
            return i;
        seen.insert(i);
    }
    return -1;
}
int main()
{

    vector<int> nums = {1, 2, 3, 3};
    int result = repeatedNTimes(nums);
    cout << result << endl;
    return 0;
}