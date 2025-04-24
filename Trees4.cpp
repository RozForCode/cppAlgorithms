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

// post order iterative traversal is tricky can be done with 2 stacks, or double pushes with one stack
vector<int> postOrderIterative(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> s;
    TreeNode *curr = root;
    TreeNode *visited = nullptr;

    while (curr != nullptr || !s.empty())
    {
        while (curr != nullptr)
        {
            s.push(curr);
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        if (visited == curr)
        {
            ans.push_back(curr->data);
        }
        else
        {
            visited = curr;
        }
        curr = curr->right;
    }
    return ans;
}