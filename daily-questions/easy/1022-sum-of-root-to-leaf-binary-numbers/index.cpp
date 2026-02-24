#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};
int solve(TreeNode *root, int val)
{
    if (!root)
        return 0;
    val = (2 * val) + root->val;
    if (!root->left && !root->right)
    {
        return val;
    }
    return solve(root->left, val) + solve(root->right, val);
}
TreeNode *buildTree(vector<int> arr)
{
    if (arr.size() == 0)
        return NULL;

    TreeNode *root = new TreeNode(arr[0]);
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size())
    {
        TreeNode *curr = q.front();
        q.pop();

        // Left child
        if (i < arr.size())
        {
            curr->left = new TreeNode(arr[i++]);
            q.push(curr->left);
        }

        // Right child
        if (i < arr.size())
        {
            curr->right = new TreeNode(arr[i++]);
            q.push(curr->right);
        }
    }

    return root;
}
int main()
{

    vector<int> arr = {1, 0, 1, 0, 1, 0, 1};
    TreeNode *root = buildTree(arr);
    cout << solve(root, 0) << endl;
    return 0;
}