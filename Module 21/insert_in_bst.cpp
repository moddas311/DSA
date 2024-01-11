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

// input tree.
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

// print tree using level order.
void levelOrder(Node *root)
{
    if (root == NULL)
        return;

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
    }
}

// insert node in tree.
void insert_node(Node *&root, int x)
{
    if (root == NULL)
    {
        root = new Node(x);
    }
    if (x < root->value)
    {
        if (root->left == NULL)
        {
            root->left = new Node(x);
        }
        else
        {
            insert_node(root->left, x);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = new Node(x);
        }
        else
        {
            insert_node(root->right, x);
        }
    }
}
int main()
{
    Node *root = inputTree();
    int insertValue;
    cin >> insertValue;

    insert_node(root, insertValue);

    // insert_node(root, 32);
    // insert_node(root, 27);
    // insert_node(root, 13);
    // insert_node(root, 22);

    levelOrder(root);
    return 0;
}