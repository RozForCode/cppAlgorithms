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
// so acc to floyd's cycle detection, the node at which
// the cycle is detected can be used to break the cycle,
// by keeping one pointer at the point and taking the next
// one to the head and looping till they are equal and then
// changing the node's next value  that was kept at the cycle
// detection node to nullptr

// now delete(by value) and reverse by myself

void deleteNode(Node *&head, int val)
{
    if (head == nullptr)
        return;
    if (head->data == val)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *current = head;
    while (current->next)
    {
        if (current->next && current->next->data == val)
        {
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        current = current->next;
    }
}

void ReverseNode(Node *&head)
{
    Node *prev = nullptr;
    Node *current = head;
    Node *temp;
    while (current)
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    head = prev;
}

// done - print, reverse, cycle detection and removal using floyd's priciple, insertion, deletion.