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
void insert_value_at_tail(Node *&head, Node *&tail, int value)
{
    Node *new_Node = new Node(value);
    if (head == NULL)
    {
        head = new_Node;
        tail = new_Node;
    }
    tail->next = new_Node;
    tail = new_Node;
}

// max value
int max_Value(Node *head)
{
    Node *tmp = head;
    int max = head->value;
    while (tmp != NULL)
    {
        if (max < tmp->value)
        {
            max = tmp->value;
        }
        tmp = tmp->next;
    }
    return max;
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
        insert_value_at_tail(head, tail, value);
    }
    cout << max_Value(head) << endl;
    return 0;
}