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
void traversal(TreeNode *root)
{
    if (!root)
        return;
    traversal(root->left);
    cout << root->data << "     ";
    traversal(root->right);
}