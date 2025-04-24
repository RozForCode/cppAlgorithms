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
// Today it's going to be post order and pre order traversal of a binary tree
// first recursive then iterative
/*
The root node of the subtree is visited first.
Next, the left subtree is recursively traversed.
Finally, the right subtree is recursively traversed.
*/
void preOrderTraversalRecursive(TreeNode *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preOrderTraversalRecursive(root->left);
    preOrderTraversalRecursive(root->right);
}

vector<int> preOrderTraversalIterative(TreeNode *root)
{
    vector<int> ans;
    TreeNode *curr = root;
    stack<TreeNode *> s;
    while (curr != nullptr || !s.empty())
    {
        ans.push_back(curr->data);
        while (curr != nullptr)
        {
            s.push(curr->left);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        ans.push_back(curr->data);
        curr = curr->right;
    }
    return ans;
}

vector<int> preOrder(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> s;
    TreeNode *curr = root;
    s.push(curr);
    while (!s.empty())
    {
        ans.push_back(curr->data);
        s.pop();
        if (curr->right != nullptr)
            s.push(curr->right);
        if (curr->left != nullptr)
            s.push(curr->left);
    }

    return ans;
}

// postorder tree traversal
void postOrderRecursive(TreeNode *root)
{
    if (!root)
        return;
    postOrderRecursive(root->left);
    postOrderRecursive(root->right);
    cout << root->data << "  -> ";
}

vector<int> postOrderIterative(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> s;
    s.push(root);
    TreeNode *curr = root;
    while (!s.empty())
    {
        while (curr->left != nullptr)
        {
            s.push(curr->left);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        ans.push_back(curr->data);
        curr = curr->right;
    }
    return ans;
}
// not right
// post order iterative traversal is tricky can be done with 2 stacks, or double pushes with one stack