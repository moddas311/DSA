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

// insert at head
void insert_at_head(Node *&head, Node *&tail, int value)
{
    Node *new_head = new Node(value);
    if (head == NULL)
    {
        head = new_head;
        tail = new_head;
        return;
    }
    new_head->next = head;
    head->prev = new_head;
    head = new_head;
}

// insert at tail
void insert_at_tail(Node *&head, Node *&tail, int value)
{
    Node *new_node = new Node(value);
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
        return;
    }

    tail->next = new_node;
    new_node->prev = tail;
    tail = tail->next;
}

// insert at any position
void insert_any_position(Node *head, int pos, int value)
{
    Node *new_node = new Node(value);
    Node *tmp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        tmp = tmp->next;
    }
    new_node->next = tmp->next;      // new node age tar next noder sathe connection holo.
    tmp->next = new_node;            // new node er sathe tar ager node connect holo.
    new_node->next->prev = new_node; // new node er ager node previous diye new node er sathe connect holo.
    new_node->prev = tmp;            // new node tar previous node er sathe connect holo.
}

// size
int size(Node *head)
{
    Node *tmp = head;
    int count = 0;
    while (tmp != 0)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

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
    // Node *head = NULL;
    // Node *tail = NULL;
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *tail = c;

    // connection
    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;

    int index, value;
    cin >> index >> value;

    if (index > size(head))
    {
        cout << "Invalit Index" << endl;
    }
    else if (index == 0)
    {
        insert_at_head(head, tail, value);
    }
    else if (index == size(head))
    {
        insert_at_tail(head, tail, value);
    }
    else
    {
        insert_any_position(head, index, value);
    }
    // print list from head
    printed_list_from_head(head);

    // print list from tail
    printed_list_from_tail(tail);
    return 0;
}