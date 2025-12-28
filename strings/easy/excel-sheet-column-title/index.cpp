#include <iostream>
using namespace std;

string convertToTitle(int columnNumber)
{
    string result = "";
    while (columnNumber > 0)
    {
        columnNumber--;
        char ch = 'A' + (columnNumber % 26);
        result.push_back(ch);
        columnNumber = columnNumber / 26;
    }
    reverse(result.begin(), result.end());
    return result;
}
int main()
{
    int columnNumber = 28;
    string result = convertToTitle(columnNumber);
    cout << " convertToTitle " << result;
    return 0;
}