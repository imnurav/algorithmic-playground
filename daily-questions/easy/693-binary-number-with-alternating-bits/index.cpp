#include <iostream>
using namespace std;
bool hasAlternatingBits(int n)
{
    int prevBit = -1;
    while (n > 0)
    {
        int currBit = n & 1;
        if (prevBit == currBit)
            return false;
        prevBit = currBit;
        n >>= 1;
    }
    return true;
}
int main()
{

    int n = 5;
    bool result = hasAlternatingBits(n);
    cout << (result ? "true" : "false") << endl;
    return 0;
}