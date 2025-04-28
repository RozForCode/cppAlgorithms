#include <iostream>
using namespace std;
#include <vector>
#include <stack>
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
// Level Order Traversal

void levelOrderTraversal(TreeNode *root, int level, vector<vector<int>> &res)
{
    if (!root)
        return;
    // creates empty vector
    // res[[emptyvector]]
    // which is accessed in res[level] where level is the index of the added vector
    if (res.size() <= level)
        res.push_back({});
    res[level].push_back(root->data);
    levelOrderTraversal(root->left, level + 1, res);
    levelOrderTraversal(root->right, level + 1, res);
}

// level order traversal iterative