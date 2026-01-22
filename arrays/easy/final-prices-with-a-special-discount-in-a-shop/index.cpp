#include <iostream>
using namespace std;
vector<int> finalPrices(vector<int> &prices)
{
    int n = prices.size();
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        int discount = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (prices[j] <= prices[i])
            {
                discount = prices[j];
                break;
            }
        }
        res.push_back(prices[i] - discount);
    }
    return res;
}
int main()
{
    vector<int> prices = {8, 4, 6, 2, 3};
    vector<int> res = finalPrices(prices);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}