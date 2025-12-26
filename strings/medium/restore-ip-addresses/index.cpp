#include <iostream>
using namespace std;
void backtrack(int index, int dots, string &s, string current,
               vector<string> &result)
{
    if (dots == 4)
    {
        if (index == s.size())
        {
            current.pop_back();
            result.push_back(current);
        }
        return;
    }

    for (int len = 1; len <= 3 && index + len <= s.size(); len++)
    {
        string part = s.substr(index, len);

        if (part.size() > 1 && part[0] == '0')
            continue;

        int value = stoi(part);
        if (value > 255)
            continue;

        backtrack(index + len, dots + 1, s, current + part + ".", result);
    }
}
vector<string> restoreIpAddresses(string s)
{
    vector<string> result;
    if (s.size() < 4 || s.size() > 12)
        return result;
    backtrack(0, 0, s, "", result);
    return result;
}
int main()
{
    vector<string> ip = restoreIpAddresses("25525511135");
    for (string ans : ip) {
        cout << ans << endl;
    }
    return 0;
}