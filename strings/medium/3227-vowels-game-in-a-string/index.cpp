#include <iostream>
using namespace std;
bool doesAliceWin(string s)
{
    int vowelCount = 0;
    for (char c : s)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            vowelCount++;
        }
    }
    return vowelCount > 0;
}
int main()
{

    string s = "leetcoder";
    if (doesAliceWin(s))
    {
        cout << "Alice wins!" << endl;
    }
    else
    {
        cout << "Bob wins!" << endl;
    }
    return 0;
}