#include <iostream>
using namespace std;
int numSteps(string s)
{
    int n = s.size();
    int step = 0;
    int carry = 0;
    for (int i = n - 1; i > 0; i--)
    {
        int digit = s[i] - 0 + carry;
        if (digit % 2 == 0)
            step++;
        else
        {
            step += 2;
            carry = 1;
        }
    }
    return step + carry;
}
int main()
{

    string s = "1101";
    int steps = numSteps(s);
    cout << "steps " << steps;
    return 0;
}