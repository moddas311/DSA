#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node *previous;
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
        this->previous = NULL;
    }
};

// insert value at tail
void insert_node(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->previous = tail;
    tail = tail->next;
}

// palindrome check
bool isPalindrome(Node *head, Node *tail)
{
    Node *i = head;
    Node *j = tail;
    while (i != j && i->next != j)
    {
        if (i->value != j->value)
        {
            return false;
        }
        i = i->next;
        j = j->previous;
    }
    if (i->value != j->value)
    {
        return false;
    }
    return true;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int value;
    while (true)
    {
        cin >> value;
        if (value == -1)
            break;
        insert_node(head, tail, value);
    }
    if (isPalindrome(head, tail))
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}