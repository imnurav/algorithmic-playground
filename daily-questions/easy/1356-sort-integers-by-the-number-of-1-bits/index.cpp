#include <iostream>
using namespace std;
int countOneBits(int num)
{
    int count = 0;
    while (num)
    {
        count += num & 1;
        num >>= 1;
    }
    return count;
}
vector<int> sortByBits(vector<int> &arr)
{
    auto lambda = [&](int &a, int &b)
    {
        int count_a = countOneBits(a);
        int count_b = countOneBits(b);
        if (count_a == count_b)
            return a < b;
        return count_a < count_b;
    };
    sort(begin(arr), end(arr), lambda);
    return arr;
}
int main()
{

    vector<int> nums = {0,1,2,3,4,5,6,7,8};
    vector<int> result;
    result = sortByBits(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}