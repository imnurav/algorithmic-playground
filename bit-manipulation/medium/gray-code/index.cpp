#include <iostream>
using namespace std;
vector<int> grayCode(int n)
{
    int size = 1 << n;
    vector<int> result;

    for (int i = 0; i < size; i++)
        result.push_back(i ^ (i >> 1));

    return result;
}
int main()
{

    vector<int> result = grayCode(2);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}