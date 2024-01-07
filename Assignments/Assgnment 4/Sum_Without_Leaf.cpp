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

Node *inputTree()
{
    int value;
    cin >> value;
    Node *root;
    if (value == -1)
        root = NULL;
    else
        root = new Node(value);
    queue<Node *> qiu;
    if (root)
        qiu.push(root);
    while (!qiu.empty())
    {
        Node *parent = qiu.front();
        qiu.pop();

        int lft, rit;
        cin >> lft >> rit;
        Node *myLeft;
        Node *myRight;

        if (lft == -1)
            myLeft = NULL;
        else
            myLeft = new Node(lft);

        if (rit == -1)
            myRight = NULL;
        else
            myRight = new Node(rit);

        parent->left = myLeft;
        parent->right = myRight;

        if (parent->left)
            qiu.push(parent->left);
        if (parent->right)
            qiu.push(parent->right);
    }
    return root;
}

int sumOfNonLeafNodes(Node *root)
{
    if (!root || (!root->left && !root->right))
    {
        return 0;
    }

    int sum = 0;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        if (current->left || current->right)
        {
            sum += current->value;
        }

        if (current->left)
        {
            q.push(current->left);
        }

        if (current->right)
        {
            q.push(current->right);
        }
    }

    return sum;
}

int main()
{
    Node *root = inputTree();
    cout << sumOfNonLeafNodes(root) << endl;
    return 0;
}
