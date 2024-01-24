#include <bits/stdc++.h>
using namespace std;

// node
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
void inser_value_at_tail(Node *&head, Node *&tail, int value)
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

// middle
void find_middle(Node *head, int count)
{
    Node *tmp = head;
    int middle = count / 2;
    for (int i = 0; i < middle - 1; i++)
    {
        tmp = tmp->next;
    }
    if (count % 2 == 1)
    {
        cout << tmp->next->value << endl;
    }
    else
    {
        cout << tmp->value << " " << tmp->next->value << endl;
    }
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int value;
    int count = 0;
    while (true)
    {
        cin >> value;
        if (value == -1)
            break;
        count++;
        inser_value_at_tail(head, tail, value);
    }
    find_middle(head, count);
    return 0;
}