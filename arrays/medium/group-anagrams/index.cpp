#include <iostream>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;

    for (string s : strs)
    {
        string key = s;
        sort(key.begin(), key.end());
        mp[key].push_back(s);
    }

    vector<vector<string>> result;
    for (auto &it : mp)
    {
        result.push_back(it.second);
    }
    return result;
}

int main()
{
    vector<string> str = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(str);
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " , ";
        }
        cout << " ]" << endl;
    }

    return 0;
}