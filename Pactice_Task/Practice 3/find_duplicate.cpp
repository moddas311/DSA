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

void insert_value(Node *&head, int value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    // tmp ekon last node e
    tmp->next = newNode;
}

void count_item(Node *head)
{
    Node *tmp = head;
    bool flag = true;
    while (tmp != NULL)
    {

        if (tmp != tmp->next)
        {
            flag = false;
            break;
        }
        tmp = tmp->next;
    }
    cout << flag << endl;
    // if (flag == 1)
    //     cout << "YES" << endl;
    // else
    // {
    //     cout << "NO";
    // }
}
int main()
{
    int value;
    Node *head = NULL;
    while (true)
    {
        cin >> value;
        if (value == -1)
        {
            break;
        }

        insert_value(head, value);
    }
    count_item(head);
    return 0;
}