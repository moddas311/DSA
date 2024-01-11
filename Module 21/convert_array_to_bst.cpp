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

// convrt array to binary search tree.
Node *arrayConvertToBST(int a[], int n, int arLeft, int arRight)
{
    // base case
    if (arLeft > arRight)
        return NULL;

    int middle = (arLeft + arRight) / 2; // middle of the array
    Node *root = new Node(a[middle]);    // create middle as root

    Node *leftRoot = arrayConvertToBST(a, n, arLeft, middle - 1);   // create left root
    Node *rightRoot = arrayConvertToBST(a, n, middle + 1, arRight); // create right root

    root->left = leftRoot;   // connect left nodes with root
    root->right = rightRoot; // connect right nodes with root

    return root; // return the final root
}

// print the tree using level order
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
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    Node *root = arrayConvertToBST(a, n, 0, n - 1);
    levelOrder(root);
    return 0;
}