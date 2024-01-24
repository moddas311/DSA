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

void prit_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
}
void delete_node(Node *head, int position)
{
    Node *tmp = head;
    for (int i = 1; i <= position - 1; i++)
    {
        tmp = tmp->next;
    }
    // tmp ekhon position-1 e orthath je node delete korbo tar ager tai.
    Node *delete_node = tmp->next; // jare delete korbo se.(store kora hoyse next e delete korar jonno)
    tmp->next = tmp->next->next;   // jare delete korbo tare skip kore er porer tai connect kora.
    delete delete_node;            // finally deleted node.
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

void delete_head(Node *&head)
{
    Node *delete_head = head;
    head = head->next;
    delete delete_head;
}
int main()
{
    Node *head = new Node(10); // linked list er 1st node ke head bola hoy.
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;

    prit_linked_list(head);
    cout << endl;
    int position;
    cin >> position;
    if (position >= size(head))
    {
        cout << "Invalid Position" << endl;
    }
    else if (position == 0)
    {
        delete_head(head);
    }
    else
    {
        delete_node(head, position);
    }
    prit_linked_list(head);
    return 0;
}