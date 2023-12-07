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
void insert_value_tail(Node *&head, Node *&tail, int value)
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
int main()
{
    Node *head = NULL;
    Node *head_2 = NULL;
    Node *tail = NULL;
    Node *tail_2 = NULL;
    int value;
    while (true)
    {
        cin >> value;
        if (value == -1)
            break;
        insert_value_tail(head, tail, value);
    }

    while (true)
    {
        cin >> value;
        if (value == -1)
            break;
        insert_value_tail(head_2, tail_2, value);
    }
    if (size(head) == size(head_2))
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}