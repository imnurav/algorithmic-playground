#include <iostream>
using namespace std;
int largestMagicSquare(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    vector<vector<long long>> row(m, vector<long long>(n + 1, 0));
    vector<vector<long long>> col(m + 1, vector<long long>(n, 0));
    vector<vector<long long>> diag1(m + 1, vector<long long>(n + 1, 0));
    vector<vector<long long>> diag2(m + 1, vector<long long>(n + 2, 0));

    // Build prefix sums
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            row[i][j + 1] = row[i][j] + grid[i][j];
            col[i + 1][j] = col[i][j] + grid[i][j];
            diag1[i + 1][j + 1] = diag1[i][j] + grid[i][j];
            diag2[i + 1][j] = diag2[i][j + 1] + grid[i][j];
        }
    }
    int maxK = min(m, n);

    for (int k = maxK; k >= 2; k--)
    {
        for (int i = 0; i + k <= m; i++)
        {
            for (int j = 0; j + k <= n; j++)
            {
                long long target = row[i][j + k] - row[i][j];
                bool ok = true;

                // Check rows
                for (int r = i; r < i + k && ok; r++)
                {
                    if (row[r][j + k] - row[r][j] != target)
                        ok = false;
                }

                // Check columns
                for (int c = j; c < j + k && ok; c++)
                {
                    if (col[i + k][c] - col[i][c] != target)
                        ok = false;
                }

                // Check diagonals
                if (ok)
                {
                    long long d1 = diag1[i + k][j + k] - diag1[i][j];
                    long long d2 = diag2[i + k][j] - diag2[i][j + k];
                    if (d1 != target || d2 != target)
                        ok = false;
                }

                if (ok)
                    return k;
            }
        }
    }
    return 1;
}

int main()
{
    vector<vector<int>> grid = {{7, 1, 4, 5, 6}, {2, 5, 1, 6, 4}, {1, 5, 4, 3, 2}, {1, 2, 7, 3, 4}};
    cout << largestMagicSquare(grid);
    return 0;
}