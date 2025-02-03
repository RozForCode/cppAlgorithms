// LinkedList
using namespace std;
#include <bits/stdc++.h>

struct Node
{
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = nullptr;
    }

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

// done - print, reverse, cycle detection and removal using floyd's principle, insertion, deletion.

// Following will be some good questions from AI bot
/*
1. Remove Duplicates from an Unsorted Linked List // using hash
2. Reverse a Linked List in Groups of Size K
3. Palindrome Linked List -
4. Intersection Point of Two Linked Lists
5. Add Two Numbers Represented by Linked Lists


6. Rotate a Linked List by K places
7. Use a linked list to represent a path in a grid-based game.
8. Recursive solution of LinkedLists
 */
#include <iostream>
#include <unordered_set>
void RemoveDuplicates(Node *head)
{
    if (head == nullptr)
        return;
    unordered_set<int> seen;
    Node *current = head;
    Node *prev = nullptr;
    while (current->next)
    {
        if (seen.find(current->data) != seen.end())
        {
            prev->next = current->next;
            delete current;
            current = prev;
        }
        else
        {
            seen.insert(current->data);
            prev = current;
            current = current->next;
        }
    }
}

Node *ReverseK(Node *head, int k)
{
    if (head == nullptr || k)
        return head;

    Node *dummy = new Node();
    dummy->next = head;
    Node *prev = dummy, *curr = dummy, *next = nullptr;

    int length = 0;
    while (curr->next != nullptr)
    {
        curr = curr->next;
        length++;
    }
    while (length >= k)
    {
        curr = prev->next;
        next = curr->next;
        for (int i = 0; i < k; i++)
        {
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }
        prev = curr;
        length -= k;
    }
    return dummy->next;
}

void Palindrome(Node *head)
{
    if (head == nullptr)
        return;
    // find the middle of the list, reverse it then compare the two halves
}
void Intersection(Node *head)
{ // easy
    if (head == nullptr)
        return;
}

Node *addNumbers(Node *l1, Node *l2)
{
    Node *dummy = new Node();
    Node *curr = dummy;
    int carry = 0;
    while (l1 || l2 || carry != 0)
    {
        int sum = (l1 ? l1->data : 0) + (l2 ? l2->data : 0) + carry;
        carry = sum / 10;
        curr->next = new Node(sum % 10);
        curr = curr->next;
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    return dummy->next;
}

void RotateK(Node *head, int k)
{
    if (head == nullptr || k == 0)
        return;
    int length = 0;
    Node *tail = head;
    while (tail->next)
    {
        tail = tail->next;
        length++;
    }
    tail->next = head;
    k = k % length;

    // rotating k times is the same as rotating k%length times
    Node *newTail = head;
    for (int i = 0; i < length - k - 1; i++)
    {
        newTail = newTail->next;
    }
    newTail->next = nullptr;
}

// *********
// rotating k times is the same as rotating k%length times
// *******
void gridPath(Node *head)
{
    if (head == nullptr)
        return;
}