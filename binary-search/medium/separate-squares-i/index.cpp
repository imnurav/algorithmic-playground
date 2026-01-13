#include <iostream>
using namespace std;
double separateSquares(vector<vector<int>> &squares)
{
    double totalArea = 0;
    double low = 1e18, high = -1e18;

    // Compute total area and bounds
    for (auto &s : squares)
    {
        double y = s[1], l = s[2];
        totalArea += l * l;
        low = min(low, y);
        high = max(high, y + l);
    }

    double half = totalArea / 2.0;

    // Binary search on y
    for (int iter = 0; iter < 80; iter++)
    { // sufficient for 1e-5
        double mid = (low + high) / 2.0;
        double below = 0;

        for (auto &s : squares)
        {
            double y = s[1], l = s[2];

            if (mid <= y)
            {
                // Entire square above
                continue;
            }
            else if (mid >= y + l)
            {
                // Entire square below
                below += l * l;
            }
            else
            {
                // Partial contribution
                below += (mid - y) * l;
            }
        }

        if (below < half)
            low = mid;
        else
            high = mid;
    }

    return low;
}
int main()
{
    vector<vector<int>> nums = {{0, 0, 2}, {1, 1, 1}};
    double result = separateSquares(nums);
    cout << "result is " << result;
    return 0;
}