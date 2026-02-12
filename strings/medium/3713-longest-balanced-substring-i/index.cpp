#include <iostream>
using namespace std;
bool checkBalance(vector<int> &freq)
{
    int common = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] == 0)
            continue;
        if (common == 0)
            common = freq[i];
        else if (freq[i] != common)
            return false;
    }
    return true;
};
void print(vector<int> &freq)
{
    int n = freq.size();
    for (int i = 0; i < n; i++)
    {
        cout << freq[i] << ((i == (n - 1)) ? "" : ",");
    }
}

int longestBalanced(string s)
{
    int n = s.size();
    int maxL = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> freq(26, 0);
        for (int j = i; j < n; j++)
        {
            freq[s[j] - 'a']++;
            if (checkBalance(freq))
                maxL = max(maxL, j - i + 1);
        }
        cout << "[ ";
        print(freq);
        cout << " ]" << endl;
    }
    return maxL;
};

int main()
{
    string s = "abbac";
    int result = longestBalanced(s);
    cout << "Longest substring unique length is " << result;
    return 0;
}