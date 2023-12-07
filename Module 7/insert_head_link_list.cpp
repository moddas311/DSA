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

// print function for print the linked list
void print_linked_list(Node *head) // jehetu head update hobe na tai head er reference lagbe na.
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

// find the size of index
int size_of_linked_list(Node *head)
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

// insert value in linked list
void insert_value(Node *head, int position, int value)
{
    Node *new_node = new Node(value);
    Node *tmp = head;
    for (int i = 1; i < position - 1; i++)
    {
        tmp = tmp->next;
    }
    // tmp ekhon position-1 e ache.
    new_node->next = tmp->next;
    tmp->next = new_node;
}

// insert head or 0th index
void insert_at_head(Node *&head, int value)
{
    Node *new_node = new Node(value);
    new_node->next = head; // head updet korar agei porer node k head banaite hobe.
    head = new_node;
}

// insert tail
void insert_at_tail(Node *&head, Node *&tail, int value)
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
int main()
{
    Node *head = new Node(10); // linked list er 1st node ke head bola hoy.
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);

    Node *tail = d;

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    cout << "tail->" << tail->value << endl;
    // insert value
    int position, value;
    cin >> position >> value;
    if (position > size_of_linked_list(head))
    {
        cout << "Invalid Index" << endl;
    }
    else if (position == 0)
    {
        insert_at_head(head, value);
    }

    else if (position == size_of_linked_list(head))
    {
        insert_at_tail(head, tail, value);
    }
    else
    {
        insert_value(head, position, value);
    }

    // printed linked list.
    print_linked_list(head);

    cout << "tail->" << tail->value;
    return 0;
}