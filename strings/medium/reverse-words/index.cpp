#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int vowelCount(const string &word)
{
    int cnt = 0;
    for (char c : word)
        if (isVowel(c))
            cnt++;
    return cnt;
}
string reverseWords(string s)
{
    string parivontel = s;
    vector<string> words;
    stringstream ss(parivontel);
    string w;
    while (ss >> w)
        words.push_back(w);
    int firstVowelCount = vowelCount(words[0]);
    for (int i = 1; i < words.size(); i++)
    {
        if (vowelCount(words[i]) == firstVowelCount)
        {
            reverse(words[i].begin(), words[i].end());
        }
    }
    string result;
    for (int i = 0; i < words.size(); i++)
    {
        if (i > 0)
            result += " ";
        result += words[i];
    }
    return result;
}
int main()
{
    // int n;
    // cin >> n;
    // vector arr(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    string s = "banana healthy";
    cout << reverseWords(s);
    return 0;
}