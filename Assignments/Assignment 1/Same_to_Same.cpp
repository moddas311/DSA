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

bool same(Node *head, Node *head_2)
{
    Node *tmp = head;
    Node *tmp_2 = head_2;
    while (tmp != NULL && tmp_2 != NULL)
    {
        if (tmp->value != tmp_2->value)
        {
            return false;
        }
        tmp = tmp->next;
        tmp_2 = tmp_2->next;
    }
    return tmp == NULL && tmp_2 == NULL;
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
    Node *head_2 = NULL;
    Node *tail_2 = NULL;
    while (true)
    {
        cin >> value;
        if (value == -1)
            break;
        insert_value(head_2, tail_2, value);
    }

    if (same(head, head_2))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}