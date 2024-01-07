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

list<int> lst;

void reverseLeafNode(Node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        lst.push_back(root->value);
    }
    reverseLeafNode(root->left);
    reverseLeafNode(root->right);
}

int main()
{
    Node *root = inputTree();
    reverseLeafNode(root);
    lst.sort(greater<int>());
    for (int value : lst)
    {
        cout << value << " ";
    }
    return 0;
}
