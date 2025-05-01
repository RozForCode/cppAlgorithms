// the task is to connect the nodes that are at the same level.
// can use level order traversal - BFS (using queue)
// or pre order traversal - DFS (using stack)
// to solve this problem
#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <queue>
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