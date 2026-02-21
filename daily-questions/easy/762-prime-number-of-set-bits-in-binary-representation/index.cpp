#include <iostream>
using namespace std;
int countBits(int n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
bool isPrime(int num)
{
    if (num == 0 || num == 1)
        return false;
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{

    int left = 6, right = 10;
    int count = 0;
    for (int i = left; i <= right; i++)
    {
        int setBitsCount = countBits(i);
        if (isPrime(setBitsCount))
            count++;
    }
    cout << count << endl;
    return 0;
}