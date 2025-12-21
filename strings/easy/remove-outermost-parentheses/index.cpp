#include <iostream>
using namespace std;
string removeOuterParentheses(string s)
{
    int count = 0;
    string res = "";
    for (auto i : s)
    {
        if (i == '(')
        {
            if (count == 0)
            {
                count++;
            }
            else
            {
                count++;
                res += '(';
            }
        }
        else
        {
            if (count == 1)
            {
                count--;
            }
            else
            {
                count--;
                res += ')';
            }
        }
    }
    return res;
}
int main()
{
    string s = "(()())(())(()(()))";
    string result = removeOuterParentheses(s);
    cout << "result is " << result << endl;
    return 0;
}