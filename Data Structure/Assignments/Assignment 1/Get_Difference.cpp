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

void insert_value_tail(Node *&head, Node *&tail, int value)
{
    Node *new_Node = new Node(value);
    if (head == NULL)
    {
        head = new_Node;
        tail = new_Node;
        return;
    }
    tail->next = new_Node;
    tail = new_Node;
}
int find_difference(Node *head)
{
    Node *tmp = head;
    int maxValue = tmp->value;
    int minValue = tmp->value;
    if (tmp->next == NULL)
    {
        return 0;
    }
    else
    {
        while (tmp != NULL)
        {
            if (maxValue < tmp->value)
            {
                maxValue = tmp->value;
            }
            if (minValue > tmp->value)
            {
                minValue = tmp->value;
            }
            tmp = tmp->next;
        }
        return maxValue - minValue;
    }
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
    Node *tail = NULL;
    int value;
    while (true)
    {
        cin >> value;
        if (value == -1)
            break;
        insert_value_tail(head, tail, value);
    }
    cout << find_difference(head);
    return 0;
}