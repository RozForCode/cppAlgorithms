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

// DFS - stack - root-left-right (preorder)
int DFSHeight(TreeNode *root)
{
    if (!root)
        return 0;
    int maxDepth = 0;
    int depth = 0;
    stack<pair<TreeNode *, int>> s;
    s.push({root, depth});
    while (!s.empty())
    {
        auto [curr, depth] = s.top();
        maxDepth = max(maxDepth, depth);
        if (!curr->left)
            s.push({curr->left, depth + 1});
        if (!curr->right)
            s.push({curr->right, depth + 1});
    }
    return maxDepth;
}

// BFS - queue - top->bottom and left ->right (level order traversal)
int BFSHeight(TreeNode *root)
{
    if (!root)
        return 0;
    int height = 0;
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *curr;
    while (!q.empty())
    {
        int levelSize = q.size();
        height++;
        for (int i = 0; i < levelSize; i++)
        {
            curr = q.front();
            q.pop();
            if (!curr->left)
                q.push(curr->left);
            if (!curr->right)
                q.push(curr->right);
        }
    }
    return height;
}