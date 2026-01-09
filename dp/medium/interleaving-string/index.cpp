#include <iostream>
using namespace std;
bool isInterleave(string s1, string s2, string s3)
{
    int n = s1.size(), m = s2.size();
    if (n + m != s3.size())
        return false;

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));

    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();

        if (i == n && j == m)
            return true;

        int k = i + j;

        // take from s1
        if (i < n && s1[i] == s3[k] && !visited[i + 1][j])
        {
            visited[i + 1][j] = true;
            q.push({i + 1, j});
        }

        // take from s2
        if (j < m && s2[j] == s3[k] && !visited[i][j + 1])
        {
            visited[i][j + 1] = true;
            q.push({i, j + 1});
        }
    }

    return false;
}
int main()
{
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    bool result = isInterleave(s1, s2, s3);
    cout << "isInterleave " << result;
    return 0;
}