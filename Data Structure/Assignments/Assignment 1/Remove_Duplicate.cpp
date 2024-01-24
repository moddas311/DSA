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

// insert value
void insert_value(Node *&head, Node *&tail, int value)
{
    Node *new_node = new Node(value);
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
        return;
    }
    tail->next = new_node;
    tail = new_node;
}

// printed list
void printed_list(Node *head)
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
        insert_value(head, tail, value);
    }
    Node *i = head;
    while (i != NULL && i->next != NULL)
    {
        Node *j = i;
        while (j->next != NULL)
        {
            if (i->value == j->next->value)
            {
                Node *duplicate = j->next;
                j->next = j->next->next;
                delete duplicate;
            }
            else
            {
                j = j->next;
            }
        }
        i = i->next;
    }
    printed_list(head);
    return 0;
}
