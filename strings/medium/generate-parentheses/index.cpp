#include <iostream>
using namespace std;
void solve(int open, int close, int n, string current,
           vector<string> &result)
{
    if (current.length() == 2 * n)
    {
        result.push_back(current);
        return;
    }

    if (open < n)
        solve(open + 1, close, n, current + "(", result);

    if (close < open)
        solve(open, close + 1, n, current + ")", result);
}
vector<string> generateParenthesis(int n)
{
    vector<string> result;
    solve(0, 0, n, "", result);
    return result;
}
int main()
{
    int n = 3;
    vector<string> ans = generateParenthesis(n);

    for (string s : ans)
    {
        cout << s << endl;
    }
    return 0;
}