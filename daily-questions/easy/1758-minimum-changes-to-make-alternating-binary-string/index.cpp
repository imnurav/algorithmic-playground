#include <iostream>
using namespace std;
int minOperations(string s)
{
    int count = 0, n = s.length();
    for (int i = 0; i < n; i++)
        count += (s[i] ^ i) & 1;

    return min(count, n - count);
}
int main()
{

    string s = "0100";
    int result = minOperations(s);
    cout << result << endl;
    return 0;
}