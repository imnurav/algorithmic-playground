#include <iostream>
using namespace std;
string countAndSay(int n)
{
    string s = "1"; // base case

    for (int i = 2; i <= n; i++)
    {
        string next = "";
        int count = 1;

        for (int j = 1; j < s.length(); j++)
        {
            if (s[j] == s[j - 1])
            {
                count++;
            }
            else
            {
                next += to_string(count);
                next += s[j - 1];
                count = 1;
            }
        }

        // add last group
        next += to_string(count);
        next += s.back();

        s = next;
    }

    return s;
}
int main()
{
    string result = countAndSay(4);
    cout << result;
    return 0;
}