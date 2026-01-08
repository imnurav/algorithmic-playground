#include <iostream>
using namespace std;
string addStrings(string num1, string num2)
{
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    string result = "";

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;

        if (i >= 0)
        {
            sum += num1[i] - '0'; // char to digit
            i--;
        }

        if (j >= 0)
        {
            sum += num2[j] - '0'; // char to digit
            j--;
        }

        result.push_back((sum % 10) + '0'); // digit to char
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());
    return result;
}
int main()
{
    string num1 = "112";
    string num2 = "119";
    string result = addStrings(num1, num2);
    cout << "Result is " << result;
    return 0;
}