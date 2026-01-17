#include <iostream>
using namespace std;
long long largestSquareArea(vector<vector<int>> &bottomLeft,
                            vector<vector<int>> &topRight)
{
    int n = bottomLeft.size();
    long long maxArea = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long xLeft = max(bottomLeft[i][0], bottomLeft[j][0]);
            long long yBottom = max(bottomLeft[i][1], bottomLeft[j][1]);
            long long xRight = min(topRight[i][0], topRight[j][0]);
            long long yTop = min(topRight[i][1], topRight[j][1]);

            if (xLeft < xRight && yBottom < yTop)
            {
                long long side = min(xRight - xLeft, yTop - yBottom);
                maxArea = max(maxArea, side * side);
            }
        }
    }

    return maxArea;
}
int main()
{
    vector<vector<int>> bottomLeft = {{1, 1}, {1, 3}, {1, 5}};
    vector<vector<int>> topRight = {{5, 5}, {5, 7}, {5, 9}};
    cout << "largestSquareArea " << largestSquareArea(bottomLeft, topRight);
    return 0;
}