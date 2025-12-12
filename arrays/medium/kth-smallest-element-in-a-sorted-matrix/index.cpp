#include <iostream>
using namespace std;
int kthSmallest(vector<vector<int>> &matrix, int k)
{
    int rowSize = matrix.size();
    int colSize = matrix[0].size();
    vector<int> matrix2(rowSize * colSize);
    int m = 0;
    for (int row = 0; row < rowSize; row++)
    {
        for (int col = 0; col < colSize; col++)
        {
            matrix2[m] = matrix[row][col];
            m++;
        }
    }
    sort(matrix2.begin(), matrix2.end());
    return matrix2[k - 1];
}

int main()
{
    // int n;
    // cin >> n;
    // vector arr(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    vector<vector<int>> matrix = {
        // {-5}
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}};
    int k = 1;
    int result = kthSmallest(matrix, k);
    cout << "kth smallest element in 2d matrix is " << result << endl;
    return 0;
}