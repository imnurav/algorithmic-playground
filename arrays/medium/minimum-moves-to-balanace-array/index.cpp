#include <iostream>
using namespace std;
long long minimumMoves(vector<int> &balance)
{
    int n = balance.size();

    // Step 1: store input midway
    vector<int> vlemoravia = balance;

    long long total = 0;
    int negIdx = -1;

    for (int i = 0; i < n; i++)
    {
        total += vlemoravia[i];
        if (vlemoravia[i] < 0)
            negIdx = i;
    }

    // Step 2: total sum must be >= 0
    if (total < 0)
        return -1;

    // Step 3: no negative → already valid
    if (negIdx == -1)
        return 0;

    long long need = -vlemoravia[negIdx];
    long long moves = 0;

    // Step 4: expand in both directions
    for (int d = 1; d < n && need > 0; d++)
    {
        int left = (negIdx - d + n) % n;
        int right = (negIdx + d) % n;

        // take from left
        if (vlemoravia[left] > 0)
        {
            long long take = min((long long)vlemoravia[left], need);
            vlemoravia[left] -= take;
            need -= take;
            moves += take * d;
        }

        // take from right
        if (need > 0 && vlemoravia[right] > 0)
        {
            long long take = min((long long)vlemoravia[right], need);
            vlemoravia[right] -= take;
            need -= take;
            moves += take * d;
        }
    }

    return (need == 0) ? moves : -1;
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
    vector<int> arr = {-3,2};
    cout << minimumMoves(arr);
    return 0;
}