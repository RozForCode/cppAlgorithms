// the task is to connect the nodes that are at the same level.
// can use level order traversal - BFS (using queue)
/*
This idea is to use level order traversal to connect nodes at the same level. A NULL is pushed after
each level to track the end of the level. As nodes are processed, each node’s nextRight pointer is set
to the next node in the queue. If a NULL is encountered and the queue isn’t empty, another NULL is
added to mark the end of the next level. This ensures that all nodes at the same level are linked.
Please refer to Connect Nodes at same Level (Level Order Traversal) for implementation.
*/
// or pre order traversal - DFS (using stack)
/*
This approach works only for Complete Binary Trees. In this method we set nextRight in Pre Order
manner to make sure that the nextRight of parent is set before its children. When we are at
node p, we set the nextRight of its left and right children. Since the tree is complete tree,
nextRight of p’s left child (p->left->nextRight) will always be p’s right child, and nextRight of p’s right child
(p->right->nextRight) will always be left child of p’s nextRight (if p is not the rightmost node at its level).
If p is the rightmost node, then nextRight of p’s right child will be NULL.
*/
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

// recursive
void levelOrder(TreeNode *root, int level, vector<vector<TreeNode *>> &ans)
{
    if (!root)
        return;
    if (ans.size() <= level)
        ans.push_back({});
    ans[level].push_back(root);
    levelOrder(root->left, level + 1, ans);
    levelOrder(root->right, level + 1, ans);
}
void convertAns(vector<vector<TreeNode *>> &ans)
{
    for (vector<TreeNode *> level : ans)
    {
        for (int i = 0; i < level.size() - 1; i++)
        {
            if (!level[++i])
            {
                level[i]->left = level[++i];
            }
            else
            {
                level[i]->left = nullptr;
            }
        }
    }
}