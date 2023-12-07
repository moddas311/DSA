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

// This function use for insert value at head position;
void insert_value_at_head(Node *&head, int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    cout << endl
         << "Inseterd at head" << endl
         << endl;
}

// This function use for delete node from position.
void delete_from_position(Node *head, int position)
{
    Node *tmp = head;
    for (int i = 1; i <= position - 1; i++)
    {
        tmp = tmp->next; // Je node delete hobe tar ager index e ache.
    }
    Node *deleteNode = tmp->next; // Je node delete korbo oita store kora hoyse.
    tmp->next = tmp->next->next;  // Je node delete hobe oita skip kore er porer ta connect kora holo.
    delete deleteNode;            // Je node ta delete kora hobe oita delete kora hoyse.

    cout << endl
         << "Deleted Position"
         << " " << position << endl
         << endl;
}

// Delete head node
void delete_head(Node *&head)
{
    Node *deleteNode = head;
    head = head->next;
    delete deleteNode;
    cout << endl
         << "Deleted Head" << endl
         << endl;
}
int main()
{
    Node *head = NULL;
    while (true)
    {
        cout << "Option 1: Insert at tail" << endl;
        cout << "Option 2: Print the linked list" << endl;
        cout << "Option 3: Insert at any position" << endl;
        cout << "Option 4: Insert at any position" << endl;
        cout << "Option 5: Delete from Position" << endl;
        cout << "Option 6: Delete from Head" << endl;
        cout << "Option 7: Terminate the program" << endl;
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
            if (positon == 0)
            {
                insert_value_at_head(head, value);
            }
            else
            {
                inserted_at_position(head, positon, value);
            }
        }
        else if (op == 4)
        {
            int value;
            cout << "Enter Value: ";
            cin >> value;
            insert_value_at_head(head, value);
        }
        else if (op == 5)
        {
            int position;
            cout << "Enter Positon: ";
            cin >> position;
            if (position == 0)
            {
                delete_head(head);
            }
            else
            {
                delete_from_position(head, position);
            }
        }
        else if (op == 6)
        {
            delete_head(head);
        }

        else if (op == 7)
        {
            break;
        }
    }

    return 0;
}