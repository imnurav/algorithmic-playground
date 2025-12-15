#include <iostream>
#include <set>
using namespace std;
set<vector<int>> s;

void getAllCombination(vector<int> &arr, int index, int target, vector<vector<int>> &ans, vector<int> &combin)
{
    if (index == arr.size() || target < 0)
        return;
    if (target == 0)
    {
        if (s.find(combin) == s.end())
        {
            ans.push_back(combin);
            s.insert(combin);
        }
        return;
    }
    combin.push_back(arr[index]);
    getAllCombination(arr, index + 1, target - arr[index], ans, combin);

    getAllCombination(arr, index, target - arr[index], ans, combin);

    combin.pop_back();
    getAllCombination(arr, index + 1, target, ans, combin);
}
int main()
{
    vector<int> candidates = {2, 3, 5};
    int target = 8;
    vector<vector<int>> ans;
    vector<int> combin;
    getAllCombination(candidates, 0, target, ans, combin);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << ((j == ans[i].size() - 1) ? " " : ", ");
        }
        cout << "]";
        cout << endl;
    }

    return 0;
}