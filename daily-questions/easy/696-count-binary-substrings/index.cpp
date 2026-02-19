#include <iostream>
using namespace std;
int countBinarySubstrings(string s)
{
    int n = s.length();
    int prevCount = 0;
    int currCount = 1;
    int result = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
            currCount++;
        else
        {
            result += min(prevCount, currCount);
            prevCount = currCount;
            currCount = 1;
        }
    }
    return result + min(prevCount, currCount);
}
int main()
{

    vector<int> nums = {1, 2, 3, 4, 5};
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}