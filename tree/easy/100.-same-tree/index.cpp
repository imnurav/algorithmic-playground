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

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (!p && !q)
        return true;
    if (!p || !q)
        return false;
    if (p->val != q->val)
        return false;
    return isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}
int main()
{

    vector<int> tree1 = {1, 2, 3};
    vector<int> tree2 = {1, -1, 2}; // -1 represents null
    TreeNode *p = buildTree(tree1);
    TreeNode *q = buildTree(tree2);

    if (isSameTree(p, q))
        cout << "Same Tree";
    else
        cout << "Different Tree";
    return 0;
}