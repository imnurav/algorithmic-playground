#include <iostream>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int price : prices)
    {
        if (price < minPrice)
        {
            minPrice = price;
        }
        else if (price - minPrice > maxProfit)
        {
            maxProfit = price - minPrice;
        }
    }

    return maxProfit;
}

int main()
{

    vector<int> arr = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(arr) << endl;
    return 0;
}