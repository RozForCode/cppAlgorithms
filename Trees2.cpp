// Inorder traversal of a binary tree
/*
Left subtree is visited first.
Root node is processed next.
Right subtree is visited last.
*/
#include <iostream>
using namespace std;
struct TreeNode
{
    int data;
    TreeNode *right;
    TreeNode *left;
    TreeNode(int value)
    {
        this->data = value;
        this->left = nullptr;
        this->right = nullptr;
        /*
        other way to initialize
        data(value)
        left(nullptr)
        right(nullptr)
        */
    }
};

// with recursion
void traversalRecursive(TreeNode *root)
{
    if (!root)
        return;
    traversalRecursive(root->left);
    cout << root->data << "     ";
    traversalRecursive(root->right);
}
// without recursion
#include <vector>
#include <stack>

vector<int> traversalIterative(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> s;
    TreeNode *curr = root;
    while (curr != nullptr || !s.empty())
    {
        while (!curr)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        ans.push_back(curr->data);
        curr = curr->right;
    }
    return ans;
}