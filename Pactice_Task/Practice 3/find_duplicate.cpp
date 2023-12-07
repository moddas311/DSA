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
    Node *tmp = head;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    // tmp ekon last node e
    tmp->next = newNode;
}

void find_duplicate(Node *head)
{
    Node *dulplicate = head;
    bool flag = false;
    while (dulplicate != NULL)
    {
        Node *tmp = dulplicate->next;
        while (tmp != NULL)
        {
            if (dulplicate->value == tmp->value)
            {
                flag = true;
                break;
            }
            tmp = tmp->next;
        }
        if (flag == true)
        {
            break;
        }
        dulplicate = dulplicate->next;
    }
    if (flag == true)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
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
    find_duplicate(head);
    return 0;
}