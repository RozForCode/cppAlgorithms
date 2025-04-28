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
// Height or depth of a tree
int height(TreeNode *root)
{
    if (!root)
        return 0;
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    return max(lHeight, rHeight) + 1;
}

// Iterative - Height or depth of a tree
// which ds? -> i think stack as we need to access the previously visited node
// it is queue
// but can also be done with stack that would be DFS which is more complex with queue it will be BFS