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

TreeNode *buildTree(vector<int> &arr)
{
    if (arr.size() == 0 || arr[0] == -1)
        return nullptr;

    TreeNode *root = new TreeNode(arr[0]);
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size())
    {
        TreeNode *curr = q.front();
        q.pop();

        // left child
        if (i < arr.size() && arr[i] != -1)
        {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        // right child
        if (i < arr.size() && arr[i] != -1)
        {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

void inorder(TreeNode *root, vector<int> &arr)
{
    if (!root)
        return;
    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}
TreeNode *buildBalanced(int l, int r, vector<int> &arr)
{
    if (l > r)
        return nullptr;
    int mid = l + (r - l) / 2;
    TreeNode *root = new TreeNode(arr[mid]);
    root->left = buildBalanced(l, mid - 1, arr);
    root->right = buildBalanced(mid + 1, r, arr);
    return root;
}
void printLevelOrder(TreeNode *root)
{
    if (!root)
        return;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();

        cout << curr->val << " ";

        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

TreeNode *balanceBST(TreeNode *root)
{
    vector<int> arr;
    inorder(root, arr);
    return buildBalanced(0, arr.size() - 1, arr);
}
void printInorder(TreeNode *root)
{
    if (!root)
        return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}
int main()
{
    vector<int> tree = {1, -1, 2, -1, 3, -1, 4, -1, -1};
    TreeNode *root = buildTree(tree);

    root = balanceBST(root);

    cout << "Inorder traversal of balanced BST: ";
    printInorder(root);
    cout << endl;

    cout << "Level order of balanced BST: ";
    printLevelOrder(root);
    cout << endl;
    return 0;
}