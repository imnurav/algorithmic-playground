#include <iostream>
using namespace std;

int singleNumber(vector<int> &arr)
{
    unordered_map<int, int> map;
    int num;
    for (int i = 0; i < arr.size(); i++)
    {
        map[arr[i]]++;
    }

    for (auto &&i : map)
    {
        if (i.second == 1)
            num = i.first;
    }
    return num;
}
int main()
{
    vector<int> arr = {2, 2, 1, 4, 4, 1, 5, 5, 6};
    int result = singleNumber(arr);
    cout << "Single Number is " << result;
    return 0;
}