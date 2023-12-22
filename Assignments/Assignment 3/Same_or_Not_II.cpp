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

// implement stack using dubly
class myStack
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int siz = 0;

    void push(int value)
    {
        siz++;
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

    void pop()
    {
        siz--;
        Node *deleteNode = tail;
        tail = tail->previous;
        if (tail == NULL)
        {
            head = NULL;
        }
        else
        {
            tail->next = NULL;
        }
        delete deleteNode;
    }

    int top()
    {
        return tail->value;
    }

    int size()
    {
        return siz;
    }

    bool empty()
    {
        if (siz == 0)
            return true;
        else
            return false;
    }
};

// implement queue using dubly
class myQueue
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int siz = 0;

    void push(int value)
    {
        siz++;
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

    void pop()
    {
        siz--;
        Node *deleteNode = head;
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
            delete deleteNode;
            return;
        }
        head->previous = NULL;
        delete deleteNode;
    }

    int front()
    {
        return head->value;
    }

    int size()
    {
        return siz;
    }

    bool empty()
    {
        if (siz == 0)
            return true;
        else
            return false;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;

    myStack stk;
    myQueue qiu;

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        stk.push(value);
    }

    for (int i = 0; i < m; i++)
    {
        int value;
        cin >> value;
        qiu.push(value);
    }

    bool flag = true;

    if (stk.size() != qiu.size())
    {
        flag = false;
    }

    while (!stk.empty() && !qiu.empty())
    {
        if (stk.top() != qiu.front())
        {
            flag = false;
            break;
        }
        stk.pop();
        qiu.pop();
    }
    if (flag)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}