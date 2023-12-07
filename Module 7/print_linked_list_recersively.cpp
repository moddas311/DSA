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
void print_recersive(Node *n)
{
    if (n == NULL)
        return;
    cout << n->value << " ";
    print_recersive(n->next);
}

void print_reverse(Node *n)
{
    if (n == NULL)
        return;
    print_reverse(n->next);
    cout << n->value << " ";
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

    print_recersive(head);
    cout << endl;
    print_reverse(head);
    return 0;
}