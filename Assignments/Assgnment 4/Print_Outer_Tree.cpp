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

void printLeft(Node *root)
{
    if (root == NULL)
        return;

    if (root->left)
        printLeft(root->left);
    else
        printLeft(root->right);

    cout << root->value << " ";
}

void printRight(Node *root)
{
    if (root == NULL)
        return;

    cout << root->value << " ";

    if (root->right)
        printRight(root->right);
    else
        printRight(root->left);
}

int main()
{
    Node *root;
    int value;
    cin >> value;
    if (value == -1)
        root == NULL;
    else
        root = new Node(value);

    queue<Node *> qiu;
    qiu.push(root);
    while (!qiu.empty())
    {
        Node *parent = qiu.front();
        qiu.pop();
        int myLeft, myRight;
        cin >> myLeft >> myRight;
        if (myLeft != -1)
            parent->left = new Node(myLeft);
        if (myRight != -1)
            parent->right = new Node(myRight);

        if (parent->left)
            qiu.push(parent->left);
        if (parent->right)
            qiu.push(parent->right);
    }

    printLeft(root->left);
    cout << root->value << " ";
    printRight(root->right);
    return 0;
}