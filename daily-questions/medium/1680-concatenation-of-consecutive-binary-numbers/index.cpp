#include <iostream>
using namespace std;
int M = 1e9 + 7;
int concatenatedBinary(int n)
{
    long result = 0;
    for (int i = 1; i <= n; i++)
    {
        int digit = log2(i) + 1;
        result = ((result << digit) % M + i) % M;
    }
    return result;
}
int main()
{

    int n = 3;
    int sum = concatenatedBinary(n);
    cout << sum << endl;
    return 0;
}