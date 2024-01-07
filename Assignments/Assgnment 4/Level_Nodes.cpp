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

        if (lft != -1)
        {
            parent->left = new Node(lft);
            qiu.push(parent->left);
        }

        if (rit != -1)
        {
            parent->right = new Node(rit);
            qiu.push(parent->right);
        }
    }
    return root;
}

void printLevelNodes(Node *root, int findLevel)
{

    queue<pair<Node *, int>> qiu;
    if (!root)
    {
        cout << "Invalid" << endl;
        return;
    }
    if (root)
    {
        qiu.push({root, 0});
    }
    while (!qiu.empty())
    {
        pair<Node *, int> parent = qiu.front();
        qiu.pop();
        Node *node = parent.first;
        int level = parent.second;

        if (level == findLevel)
        {
            cout << node->value << " ";
        }

        if (node->left)
        {
            qiu.push({node->left, level + 1});
        }

        if (node->right)
        {
            qiu.push({node->right, level + 1});
        }
    }
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

    int findLevel;
    cin >> findLevel;
    if (maxHighest(root) <= findLevel)
    {
        cout << "Invalid" << endl;
    }
    printLevelNodes(root, findLevel);

    return 0;
}
