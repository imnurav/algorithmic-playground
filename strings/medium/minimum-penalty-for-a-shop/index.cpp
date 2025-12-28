#include <iostream>
using namespace std;
int bestClosingTime(string customers)
{
    int n = customers.size();

    // Initial penalty: shop closed all day
    int penalty = 0;
    for (char c : customers)
        if (c == 'Y')
            penalty++;

    int minPenalty = penalty;
    int bestHour = 0;

    // Move closing hour from 1 to n
    for (int i = 0; i < n; i++)
    {
        if (customers[i] == 'Y')
        {
            penalty--; // now open, no penalty
        }
        else
        {
            penalty++; // open but no customer
        }

        if (penalty < minPenalty)
        {
            minPenalty = penalty;
            bestHour = i + 1;
        }
    }

    return bestHour;
}
int main()
{
    string customers = "YYNY";
    int bestTime = bestClosingTime(customers);
    cout << "Best Close Time with Minimum Penalty is " << bestTime << endl;
    return 0;
}