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
        return;
    }
    tail->next = new_node;
    tail = new_node;
}
int find_index(Node *head, int terget)
{
    Node *tmp = head;
    int index = 0;
    while (tmp != NULL)
    {
        if (tmp->value == terget)
        {
            return index;
        }
        tmp = tmp->next;
        index++;
    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
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
        int x;
        cin >> x;
        int result = find_index(head, x);
        cout << result << endl;
    }
    return 0;
}