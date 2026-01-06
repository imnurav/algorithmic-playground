#include <iostream>
using namespace std;
double myPow(double x, int n)
{
    long long exp = n;
    if (exp < 0)
    {
        x = 1.0 / x;
        exp = -exp;
    }

    double result = 1.0;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result *= x;
        x *= x;
        exp /= 2;
    }

    return result;
}
int main()
{
    double x = 2.10000;
    int n = 3;
    double result = myPow(x, n);
    cout << "Result of expression is " << result << endl;
    return 0;
}