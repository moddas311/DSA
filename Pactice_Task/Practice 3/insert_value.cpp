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

void insert_value(Node *&head, Node *&tail, int value)
{
    Node *new_node = new Node(value);
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    tail->next = new_node;
    tail = new_node;
}

void insert_value_at_index(Node *head, int position, int value)
{
    Node *new_node = new Node(value);
    Node *tmp = head;
    for (int i = 1; i <= position - 1; i++)
    {
        tmp = tmp->next;
    }
    new_node->next = tmp->next;
    tmp->next = new_node;
}

void insert_at_head(Node *&head, int value)
{
    Node *new_head = new Node(value);
    new_head->next = head;
    head = new_head;
}

int size_of_linked_list(Node *head)
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
void print_linked_list(Node *head)
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
    while (true)
    {
        int value;
        cin >> value;
        if (value == -1)
        {
            break;
        }
        insert_value(head, tail, value);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int index, value;
        cin >> index >> value;
        if (index == 0)
        {
            insert_at_head(head, value);
        }
        else if (index > size_of_linked_list(head))
        {
            cout << "Invalid" << endl;
            continue;
        }
        else if (index == size_of_linked_list(head))
        {
            insert_value(head, tail, value);
        }
        else
        {
            insert_value_at_index(head, index, value);
        }
        print_linked_list(head);
    }
    return 0;
}