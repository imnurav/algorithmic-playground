#include <iostream>
using namespace std;

// Function to search for a target value in a 2D matrix timed O(n*m)
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    for (int row = 0; row < matrix.size(); row++)
    {
        for (int col = 0; col < matrix[0].size(); col++)
        {
            cout << matrix[row][col] << " ";
            // if (matrix[row][col] == target)
            //     return true;
        }
    }
    return false;
}
// optimized approach O(log(n*m))
bool searchMatrixOptimized(vector<vector<int>> &matrix, int target)
{
    if (matrix.empty() || matrix[0].empty())
        return false;
    int rows = matrix.size();
    int cols = matrix[0].size();
    int left = 0;
    int right = rows * cols - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int midValue = matrix[mid / cols][mid % cols];
        if (midValue == target)
            return true;
        else if (midValue < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}
int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int target = 5;

    bool result = searchMatrix(matrix, target);

    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}