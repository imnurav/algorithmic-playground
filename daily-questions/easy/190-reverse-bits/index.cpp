#include <iostream>
using namespace std;

int reverseBits(int n)
{
    if (n == 0)
        return 0;
    int result = 0;
    for (int i = 1; i <= 32; i++)
    {
        result = result << 1;
        result = (result | (n & 1));
        n = n >> 1;
    }
    return result;
}
int main()
{

    int n = 43261596;
    cout << reverseBits(n) << endl;
    return 0;
}