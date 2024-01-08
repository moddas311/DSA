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
        // 1. ber kore ana
        Node *parent = qiu.front();
        qiu.pop();

        // 2. jabotiyo ja kaj ache
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

        // 3. children gula ke push kora.
        if (parent->left)
            qiu.push(parent->left);
        if (parent->right)
            qiu.push(parent->right);
    }
    return root;
}

int maxHighest(Node *root)
{
    if (root == NULL)
        return 0;
    int leftSUbTree = maxHighest(root->left);
    int rightSubTree = maxHighest(root->right);
    return max(leftSUbTree, rightSubTree) + 1;
}

int main()
{
    Node *root = inputTree();
    cout << maxHighest(root) << endl;
    return 0;
}