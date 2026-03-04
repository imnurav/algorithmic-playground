#include <iostream>
using namespace std;

int numSpecial(vector<vector<int>> &mat)
{
    int result = 0;
    int m = mat.size();
    int n = mat[0].size();
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (mat[row][col] == 0)
                continue;

            bool good = true;
            // Check Row
            for (int r = 0; r < m; r++)
            {
                if (r != row && mat[r][col] == 1)
                {
                    good = false;
                    break;
                }
            }

            // Check Col
            for (int c = 0; c < n; c++)
            {
                if (c != col && mat[row][c] == 1)
                {
                    good = false;
                    break;
                }
            }

            if (good)
                result++;
        }
    }
    return result;
}
int main()
{

    // vector<vector<int>> nums = {{1, 0, 0}, {0, 0, 1}, {1, 0, 0}};
    vector<vector<int>> nums = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int result = numSpecial(nums);
    cout << result << endl;
    return 0;
}