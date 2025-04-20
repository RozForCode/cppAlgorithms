// // making a simple tree
// struct TreeNode
// {
//     int data;
//     TreeNode *right;
//     TreeNode *left;
//     TreeNode(int value)
//     {
//         this->data = value;
//         this->left = nullptr;
//         this->right = nullptr;
//         /*
//         other way to initialize
//         data(value)
//         left(nullptr)
//         right(nullptr)
//         */
//     }
// };

// // lets make a print function to print this tree beautifully
// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <string>
// #include <iomanip>
// #include <algorithm>
// #include <queue>
// // The #include <iomanip> header in C++ gives you access to "input/output manipulators" — these
// // are tools that help you format text and numbers when printing to the console (or reading input).
// using namespace std;
// // recursive method to get the height of the tree
// int getHeight(TreeNode *root)
// {
//     if (!root)
//         return 0;
//     return 1 + max(getHeight(root->right), getHeight(root->left));
// }
// void printTree(TreeNode *root)
// {
//     if (!root)
//         return;
//     int maxLevel = getHeight(root);
//     int maxWidth = pow(2, maxLevel) * 2;
//     queue<TreeNode *> q;
//     q.push(root);

//     for (int level = 1; level <= maxLevel; level++)
//     {
//         int levelNodes = pow(2, level - 1);
//         int spacing = maxWidth / levelNodes;
//         for (int i = 0; i < levelNodes; i++)
//         {
//             TreeNode *curr = q.front();
//             q.pop();
//             if (curr)
//                 cout << setw(spacing) << curr->data;
//             else
//                 cout << setw(spacing) << " ";
//             if (curr)
//             {
//                 q.push(curr->left);
//                 q.push(curr->right);
//             }
//             else
//             {
//                 q.push(nullptr);
//                 q.push(nullptr);
//             }
//         }
//         cout << endl;
//         if (level != maxLevel)
//         {
//             for (int j = 0; j < levelNodes; j++)
//             {
//                 cout << setw(spacing / 2) << ((j % 2 == 0) ? "/" : "\\");

//                 cout << setw(spacing / 2) << " ";
//             }
//             cout << endl;
//         }
//     }
// }
// int main()
// {
//     TreeNode *root = new TreeNode(10);
//     root->left = new TreeNode(9);
//     root->right = new TreeNode(8);
//     root->right->left = new TreeNode(7);
//     root->right->right = new TreeNode(6);
//     printTree(root);
//     return 0;
// }
#include <iostream>
#include <queue>
#include <cmath>
#include <string>
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
    }
};

int getHeight(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + max(getHeight(root->right), getHeight(root->left));
}

void printTree(TreeNode *root)
{
    if (!root)
        return;

    int maxLevel = getHeight(root);
    queue<TreeNode *> q;
    q.push(root);

    for (int level = 1; level <= maxLevel; level++)
    {
        int levelNodes = pow(2, level - 1);         // Number of nodes at this level
        int spacing = pow(2, maxLevel - level) - 1; // Spacing between nodes

        // Print the nodes at the current level
        for (int i = 0; i < levelNodes; i++)
        {
            TreeNode *curr = q.front();
            q.pop();

            // Print spacing before the node
            cout << string(spacing, ' ');

            // Print the node or a blank space
            if (curr)
                cout << curr->data;
            else
                cout << " ";

            // Print spacing after the node
            cout << string(spacing, ' ');

            // Push children into the queue
            if (curr)
            {
                q.push(curr->left);
                q.push(curr->right);
            }
            else
            {
                q.push(nullptr);
                q.push(nullptr);
            }
        }
        cout << endl;

        // Print the branches (/ and \) for the next level
        if (level != maxLevel)
        {
            for (int j = 0; j < levelNodes; j++)
            {
                // Spacing before the branch
                cout << string(pow(2, maxLevel - level - 1), ' ');

                // Print the left branch '/'
                cout << "/";

                // Spacing between the branches
                cout << string(pow(2, maxLevel - level + 1) - 1, ' ');

                // Print the right branch '\'
                cout << "\\";

                // Spacing after the branch
                cout << string(pow(2, maxLevel - level - 1), ' ');
            }
            cout << endl;
        }
    }
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(6);
    printTree(root);
    return 0;
}