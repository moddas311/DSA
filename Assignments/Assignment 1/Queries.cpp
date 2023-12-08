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

// insert tail
void tail_insert(Node *&head, int value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

// insert at head
void insert_at_head(Node *&head, int value)
{
    Node *new_head = new Node(value);
    new_head->next = head;
    head = new_head;
}

// Delete head node
void delete_head(Node *&head)
{
    Node *deleteNode = head;
    if (head == NULL)
    {
        return;
    }
    head = head->next;
    delete deleteNode;
}

// delete node
void delete_node(Node *head, int index)
{
    Node *tmp = head;
    if (head == NULL)
    {
        return;
    }
    for (int i = 1; i <= index - 1; i++)
    {
        tmp = tmp->next;
    }
    Node *deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    delete deleteNode;
}

int size(Node *head)
{
    Node *tmp = head;
    int count = 0;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}
// print the linked list.
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
    int query;
    cin >> query;
    while (query--)
    {
        int index, value;
        cin >> index >> value;
        if (index == 0)
        {
            if (head == NULL)
            {
                tail_insert(head, value);
                printed_list(head);
            }
            else
            {
                insert_at_head(head, value);
                printed_list(head);
            }
        }
        else if (index == 1)
        {
            tail_insert(head, value);
            printed_list(head);
        }
        else if (index == 2)
        {
            if (value == 0)
            {
                delete_head(head);
                printed_list(head);
            }
            else if (value < size(head))
            {
                delete_node(head, value);
                printed_list(head);
            }
            else
            {
                printed_list(head);
            }
        }
    }
    return 0;
}