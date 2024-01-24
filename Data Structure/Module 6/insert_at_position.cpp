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

// This function use for insert node at the end position.
void insert_at_tail(Node *&head, int value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        cout << endl
             << "Inserted at head." << endl
             << endl;
        return;
    }
    Node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    // tmp ekon last node e
    tmp->next = newNode;
    cout << endl
         << "Inserted at tail." << endl
         << endl;
}

// This function use for print linked list.
void print_linked_list(Node *head)
{
    cout << endl;
    Node *tmp = head;
    cout << "Your linked list: ";
    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl
         << endl;
}

// This function use for insert node any position.
void inserted_at_position(Node *head, int position, int value)
{
    Node *newNode = new Node(value);
    Node *tmp = head;
    for (int i = 1; i <= position - 1; i++)
    {
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
    cout << endl
         << endl
         << "Inserted at position" << position << endl
         << endl;
};
int main()
{
    Node *head = NULL;
    while (true)
    {
        cout << "Option 1: Insert at tail" << endl;
        cout << "Option 2: Print the linked list" << endl;
        cout << "Option 3: Insert at any position" << endl;
        cout << "Option 4: Terminate the program" << endl;
        int op;
        cin >> op;
        if (op == 1)
        {
            cout << "Enter a value: ";
            int v;
            cin >> v;
            insert_at_tail(head, v);
        }
        else if (op == 2)
        {
            print_linked_list(head);
        }
        else if (op == 3)
        {
            cout << "Enter Your Position: ";
            int positon, value;
            cin >> positon;
            cout << "ENter Your Value: ";
            cin >> value;
            inserted_at_position(head, positon, value);
        }

        else if (op == 4)
        {
            break;
        }
    }

    return 0;
}