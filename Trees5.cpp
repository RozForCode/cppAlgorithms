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
// it will be FIFO so using queue
#include <queue>
vector<vector<int>> levelOrder(TreeNode *root)
{
    if (!root)
        return {};
    queue<TreeNode *> q;
    vector<vector<int>> ans;
    q.push(root);
    int currLevel = 0;
    TreeNode *curr;
    while (!q.empty())
    {
        int len = q.size();
        ans.push_back({});

        for (int i = 0; i < len; i++)
        {
            curr = q.front();
            ans[currLevel].push_back(curr->data);
            q.pop();
            if (!curr->left)
                q.push(curr->left);
            if (!curr->right)
                q.push(curr->right);
        }
        currLevel++;
    }
    return ans;
}