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

// insert node in the list
void insert_node_at_tail(Node *&head, Node *&tail, int value)
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

// reverse the dubly list
void reverse_list(Node *head, Node *tail)
{
    Node *i = head;
    Node *j = tail;
    while (i != j && i->next != j)
    {
        swap(i->value, j->value);
        i = i->next;
        j = j->previous;
    }
    swap(i->value, j->value);
}

// print the list
void print_the_list(Node *head)
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
    Node *head = NULL;
    Node *tail = NULL;
    int value;
    while (true)
    {
        cin >> value;
        if (value == -1)
            break;
        insert_node_at_tail(head, tail, value);
    }

    reverse_list(head, tail);

    print_the_list(head);
    return 0;
}