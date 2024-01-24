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

// insert value at head
void insert_value_at_head(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->previous = newNode;
    head = newNode;
}

// insert at any position
void insert_at_any_position(Node *head, int index, int value)
{
    Node *newNode = new Node(value);
    Node *tmp = head;
    for (int i = 1; i <= index - 1; i++)
    {
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
    newNode->next->previous = newNode;
    newNode->previous = tmp;
}

// insert at tail
void insert_at_tail(Node *&head, Node *&tail, int value)
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

// size
int size(Node *head)
{
    int count = 0;
    Node *tmp = head;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

// print from head
void print_from_head(Node *head)
{
    cout << "L"
         << " "
         << "->"
         << " ";
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

// print from tail
void print_from_tail(Node *tail)
{
    cout << "R"
         << " "
         << "->"
         << " ";
    Node *tmp = tail;
    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->previous;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int query;
    cin >> query;
    while (query--)
    {
        int index, value;
        cin >> index >> value;
        if (index > size(head))
        {
            cout << "Invalid" << endl;
        }
        else if (index == 0)
        {
            insert_value_at_head(head, tail, value);
            print_from_head(head);
            print_from_tail(tail);
        }
        else if (index == size(head))
        {
            insert_at_tail(head, tail, value);
            print_from_head(head);
            print_from_tail(tail);
        }
        else
        {
            insert_at_any_position(head, index, value);
            print_from_head(head);
            print_from_tail(tail);
        }
    }

    return 0;
}