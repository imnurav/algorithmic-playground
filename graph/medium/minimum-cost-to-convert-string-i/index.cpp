#include <iostream>
using namespace std;
void FloidWarshall(vector<vector<long long>> &adjMatrix,
                   vector<char> &original, vector<char> &changed,
                   vector<int> &cost)
{
    for (int i = 0; i < original.size(); i++)
    {
        int s = original[i] - 'a';
        int t = changed[i] - 'a';
        adjMatrix[s][t] = min(adjMatrix[s][t], (long long)cost[i]);
    }

    for (int k = 0; k < 26; k++)
    {
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                adjMatrix[i][j] =
                    min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
            }
        }
    }
}
long long minimumCost(string source, string target, vector<char> &original,
                      vector<char> &changed, vector<int> &cost)
{
    vector<vector<long long>> adjMatrix(26, vector<long long>(26, INT_MAX));

    FloidWarshall(adjMatrix, original, changed, cost);
    long long ans = 0;
    for (int i = 0; i < source.size(); i++)
    {
        if (source[i] == target[i])
            continue;
        int s = source[i] - 'a';
        int t = target[i] - 'a';

        if (adjMatrix[s][t] == INT_MAX)
            return -1;

        ans += adjMatrix[s][t];
    }
    return ans;
}
int main()
{
    string source = "abcd";
    string target = "acbe";
    vector<char> original = {'a', 'b', 'c', 'c', 'e', 'd'};
    vector<char> changed = {'b', 'c', 'b', 'e', 'b', 'e'};
    vector<int> cost = {2, 5, 5, 1, 2, 20};
    cout << minimumCost(source, target, original, changed, cost) << endl;
    return 0;
}