#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};
// reverse singly list
void reverse_list(Node *&head, Node *current)
{
    if (current->next == NULL)
    {
        head = current;
        return;
    }
    reverse_list(head, current->next);
    current->next->next = current;
    current->next = NULL;
}

// print linked list
void print_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);
    Node *e = new Node(50);
    Node *a = new Node(60);

    head->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = a;
    // print_list(head);
    reverse_list(head, head);
    print_list(head);
    return 0;
}