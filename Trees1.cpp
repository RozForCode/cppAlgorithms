// making a simple tree
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

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(6);
    return 0;
}

// lets make a print function to print this tree beautifully
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <iomanip>
// The #include <iomanip> header in C++ gives you access to "input/output manipulators" — these
// are tools that help you format text and numbers when printing to the console (or reading input).

// recursive method to get the height of the tree
int getHeight(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + max(getHeight(root->right), getHeight(root->left));
}