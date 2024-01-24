#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node *prev;
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

// print the value of dubly linked list
void printed_list_from_head(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

// print the value of dubly linked list
void printed_list_from_tail(Node *tail)
{
    Node *tmp = tail;
    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}
int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *tail = b;
    // connection
    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;

    // print list from head
    printed_list_from_head(head);

    // print list from tail
    printed_list_from_tail(tail);
    return 0;
}