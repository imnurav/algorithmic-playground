#include <iostream>
using namespace std;

int lastStoneWeight(vector<int> &stones)
{
    while (stones.size() > 1)
    {
        sort(stones.begin(), stones.end());
        int x = stones.back();
        stones.pop_back();

        int y = stones.back();
        stones.pop_back();

        if (x != y)
            stones.push_back(x - y);
    }
    return stones.empty() ? 0 : stones[0];
}

int main()
{
    // int n;
    // cin >> n;
    // vector<int> arr(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    vector<int> stones = {2,7,4,1,8,1};
    cout << lastStoneWeight(stones);
    return 0;
}