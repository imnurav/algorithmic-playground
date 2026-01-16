#include <iostream>
#include <unordered_set>
using namespace std;
int maximizeSquareArea(int m, int n, vector<int> &hFences,
                       vector<int> &vFences)
{
    const int MOD = 1e9 + 7;

    // Add boundary fences
    hFences.push_back(1);
    hFences.push_back(m);
    vFences.push_back(1);
    vFences.push_back(n);

    sort(hFences.begin(), hFences.end());
    sort(vFences.begin(), vFences.end());

    unordered_set<long long> heights;

    // All possible horizontal distances
    for (int i = 0; i < hFences.size(); i++)
    {
        for (int j = i + 1; j < hFences.size(); j++)
        {
            heights.insert(hFences[j] - hFences[i]);
        }
    }

    long long maxSide = -1;

    // Check vertical distances
    for (int i = 0; i < vFences.size(); i++)
    {
        for (int j = i + 1; j < vFences.size(); j++)
        {
            long long width = vFences[j] - vFences[i];
            if (heights.count(width))
            {
                maxSide = max(maxSide, width);
            }
        }
    }

    if (maxSide == -1)
        return -1;
    return (maxSide * maxSide) % MOD;
}
int main()
{
    int m = 6, n = 7;
    vector<int> hFences = {2}, vFences = {4};
    cout << "Maximum Square is " << maximizeSquareArea(m, n, hFences, vFences);
    return 0;
}