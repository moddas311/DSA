#include <bits/stdc++.h>

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Queue
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

    Queue() {}

    bool isEmpty() { return sz == 0; }

    void enqueue(int data)
    {
        sz++;
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            sz--;
            Node *deleteNode = head;
            head = head->next;
            return deleteNode->data;
            delete deleteNode;
        }
    }

    int front()
    {
        if (!isEmpty())
        {
            return head->data;
        }
        else
            return -1;
    }
};