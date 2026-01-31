#include <iostream>
using namespace std;
char nextGreatestLetter(vector<char> &letters, char target)
{
    int left = 0, right = letters.size() - 1;
    char result = letters[0]; // wrap-around default

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (letters[mid] > target)
        {
            result = letters[mid];
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return result;
}
int main()
{
    vector<char> letters = {'c','f','j'};
    char target = 'a';
    cout << nextGreatestLetter(letters, target) << endl;
    return 0;
}