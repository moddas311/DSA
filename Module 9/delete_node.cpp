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

// delete node
void delete_node(Node *head, int position)
{
    Node *tmp = head;
    for (int i = 1; i <= position - 1; i++)
    {
        tmp = tmp->next;
    }
    Node *delete_node = tmp->next;
    tmp->next = tmp->next->next;
    tmp->next->prev = tmp;
    delete delete_node;
}

// delete tail
void delete_tail(Node *&tail)
{
    Node *delete_node = tail;
    tail = tail->prev;
    delete delete_node;
    tail->next = NULL;
}

// delete head
void delete_head(Node *&head)
{
    Node *delete_node = head;
    head = head->next;
    delete delete_node;
    head->prev = NULL;
}
//  size
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

    // input index for delete node
    int index;
    cin >> index;

    if (index >= size(head))
    {
        cout << "Invalid index" << endl;
    }
    else if (index == 0)
    {
        delete_head(head);
    }
    else if (index == size(head) - 1)
    {
        delete_tail(tail);
    }

    else
    {
        delete_node(head, index);
    }

    // print from the head
    printed_list_from_head(head);
    // print list from tail
    printed_list_from_tail(tail);
    return 0;
}