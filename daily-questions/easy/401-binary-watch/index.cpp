#include <iostream>
using namespace std;
vector<string> readBinaryWatch(int turnedOn)
{
    vector<string> result;
    for (int HH = 0; HH < 12; HH++)
    {
        for (int MM = 0; MM < 60; MM++)
        {
            if (__builtin_popcount(HH) + __builtin_popcount(MM) ==
                turnedOn)
            {
                string hour = to_string(HH);
                string minute = (MM < 10 ? "0" : "") + to_string(MM);
                result.push_back(hour + ":" + minute);
            }
        }
    }
    return result;
}
int main()
{

    int turnedOn = 1;
    vector<string> result = readBinaryWatch(turnedOn);
    for (const string &time : result)    {
        cout << time << endl;
    }
    return 0;
}