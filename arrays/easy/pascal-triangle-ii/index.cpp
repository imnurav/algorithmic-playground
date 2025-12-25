#include <iostream>
using namespace std;
vector<int> generate(int rowIndex)
{
    vector<vector<int>> triangle;
    for (int i = 0; i <= rowIndex; i++)
    {
        vector<int> row(i + 1, 1);
        for (int j = 1; j < i; j++)
        {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle.push_back(row);
    }
    return triangle[rowIndex];
}
int main()
{
    int numRows = 3;
    vector<int> result = generate(numRows);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}