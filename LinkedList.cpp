// LinkedList
using namespace std;
#include <bits/stdc++.h>

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
    Node(int val, Node *node)
    {
        data = val;
        next = node;
    }
};

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "Null/n";
}
/*
Yes! Node*& head is a reference to a pointer. Let's break it down:

Understanding Node*& head
Node* head → A pointer to a Node (stores the address of a node).
Node*& head → A reference to a pointer to a Node.
Why Use Node*& head?
If we pass a pointer normally (Node* head), it gets copied, so changes inside the function won't affect the original pointer.
By passing a reference to a pointer (Node*& head), we allow the function to modify the original pointer.

*/

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next)
        temp = temp->next; // while(temp->next) and while(temp->next != nullptr) are functionally the same
    temp->next = newNode;
}

bool hasCycle(Node *node)
{
    Node *slow = node;
    Node *fast = node;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

// works acc to Floyd’s Cycle Detection Algorithm.
void removeCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    do
    {
        if (fast || fast->next)
            return;
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    // fast and slow are at the same node
    slow = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = nullptr;
}