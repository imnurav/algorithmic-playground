#include <iostream>
using namespace std;
int minPartitions(string n)
{
    int count = 0;

    while (true)
    {
        bool changed = false;

        for (char &ch : n)
        {
            if (ch != '0')
            {
                ch--; // subtract 1
                changed = true;
            }
        }

        if (!changed)
            break;

        count++;
    }

    return count;
}
int main()
{

    string n = "27346209830709182346";
    int result = minPartitions(n);
    cout << result << endl;
    return 0;
}