#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrder(Node *root)
{
    queue<Node *> qiu;
    qiu.push(root);
    while (!qiu.empty())
    {
        // 1. ber kore ana
        Node *first = qiu.front();
        qiu.pop();

        // jabotio ja kaj ache
        cout << first->value << " ";

        // 3. tar children gula ke rakha
        if (first->left)
            qiu.push(first->left);
        if (first->right)
            qiu.push(first->right);

        // right theke left er jonno
        /*
        if (first->right)
            qiu.push(first->right);
        if (first->left)
            qiu.push(first->left);
        */
    }
}

int main()
{
    Node *root = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);
    Node *e = new Node(60);
    Node *f = new Node(70);
    Node *g = new Node(80);
    Node *h = new Node(90);
    Node *i = new Node(100);

    // connection
    root->left = a;
    root->right = b;
    a->left = c;
    a->right = h;
    c->right = e;
    b->right = d;
    d->left = f;
    d->right = g;
    h->right = i;

    levelOrder(root);

    return 0;
}