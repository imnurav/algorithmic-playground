#include <iostream>
using namespace std;

int binaryGap(int n)
{
    int prev = INFINITY, current = 0;
    int maxGap = 0;
    while (n)
    {
        if (n & 1)
        {
            maxGap = max(maxGap, current - prev);
            prev = current;
        }
        current++;
        n >>= 1;
    }
    return maxGap;
}

int main()
{
    int n = 22;
    cout << binaryGap(n) << endl;
    return 0;
}