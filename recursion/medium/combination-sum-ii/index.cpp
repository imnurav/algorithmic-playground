#include <iostream>
using namespace std;

void recursiveCombinationSum2(vector<int> &candidates, int target, int start, vector<int> &current, vector<vector<int>> &result)
{
    if (target == 0)
    {
        result.push_back(current);
        return;
    }
    for (int i = start; i < candidates.size(); i++)
    {
        if (i > start && candidates[i] == candidates[i - 1])
            continue;
        if (candidates[i] > target)
            break;
        current.push_back(candidates[i]);
        recursiveCombinationSum2(candidates, target - candidates[i], i + 1, current, result);
        current.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target, vector<vector<int>> &result)
{
    sort(candidates.begin(), candidates.end());
    vector<int> current;
    recursiveCombinationSum2(candidates, target, 0, current, result);
    return result;
}

int main()
{
    vector<int> candidates = {2, 5, 2, 1, 2};
    int target = 5;
    vector<vector<int>> result;
    combinationSum2(candidates, target, result);
    cout << "Unique combinations that sum to " << target << " are:" << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << ((j == result[i].size() - 1) ? " " : ", ");
        }
        cout << "]";
        cout << endl;
    }

    return 0;
}