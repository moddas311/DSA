#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node *previous;
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
        this->previous = NULL;
    }
};

// insert node at tail
void insert_at_tail(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->previous = tail;
    tail = tail->next;
}

// same kina find out
bool find_same(Node *head, Node *head_2)
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

    // 1 No. dubly link.
    while (true)
    {
        cin >> value;
        if (value == -1)
            break;
        insert_at_tail(head, tail, value);
    }

    // 2 No. dubly link
    Node *head_2 = NULL;
    Node *tail_2 = NULL;
    while (true)
    {
        cin >> value;
        if (value == -1)
            break;
        insert_at_tail(head_2, tail_2, value);
    }
    if (find_same(head, head_2) == true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}