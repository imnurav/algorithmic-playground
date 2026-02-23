#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
bool hasAllCodes(string s, int k)
{
    unordered_set<string> st;
    int n = s.length();
    int total = (1 << k);
    for (int i = k; i <= n; i++)
    {
        string sub = s.substr(i - k, k);
        if (!st.count(sub))
        {
            st.insert(sub);
            total--;
        }
        if (total == 0)
        {
            return true;
        }
    }
    return false;
}
int main()
{

    string s = "00110110";
    int k = 2;
    int result = hasAllCodes(s, k);
    cout << (result ? "true" : "false") << endl;
    return 0;
}