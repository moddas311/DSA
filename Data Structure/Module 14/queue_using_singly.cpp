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
class myQueue
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

    void push(int value)
    {
        sz++;
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = tail->next;
    }

    void pop()
    {
        sz--;
        Node *deleNode = head;
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
    }

    int front()
    {
        return head->value;
    }

    int size()
    {
        return sz;
    }

    bool empty()
    {
        if (sz == 0)
            return true;
        else
            return false;
    }
};
int main()
{
    myQueue q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        q.push(value);
    }
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}