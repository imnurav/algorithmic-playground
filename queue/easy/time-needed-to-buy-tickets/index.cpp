#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int timeRequiredToBuy(vector<int> &tickets, int k)
{
    queue<pair<int, int>> q;

    for (int i = 0; i < tickets.size(); i++)
    {
        q.push({tickets[i], i});
    }
    int time = 0;

    while (!q.empty())
    {
        auto [rem, idx] = q.front();
        q.pop();

        rem--;
        time++;

        if (rem == 0)
            if (idx == k)
                return time;
            else
                q.push({rem, idx});
    }
    return time;
}
int main()
{
    vector<int> tickets = {2, 3, 2};
    int k = 2;
    cout << timeRequiredToBuy(tickets, k) << endl;
    return 0;
}