#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

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
vector<vector<int>> levelOrder(TreeNode *root)
{
    if (!root)
        return {};

    vector<vector<int>> result;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            level.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        result.push_back(level);
    }

    return result;
}
int main()
{

    vector<int> tree = {3, 9, 20, -1, -1, 15, 7}; // -1 represents null
    TreeNode *root = buildTree(tree);
    vector<vector<int>> result = levelOrder(root);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}