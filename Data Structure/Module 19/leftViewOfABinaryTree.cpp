#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };
************************************************************/

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here

    bool freq[3002] = {false};
    queue<pair<TreeNode<int> *, int>> Q;
    if (root)
        Q.push({root, 1});

    vector<int> V;

    while (!Q.empty())
    {
        pair<TreeNode<int> *, int> parent = Q.front();
        Q.pop();
        TreeNode<int> *node = parent.first;
        int level = parent.second;

        if (freq[level] == false)
        {
            V.push_back(node->data);
            freq[level] = true;
        }

        if (node->left)
        {
            Q.push({node->left, level + 1});
        }

        if (node->right)
        {
            Q.push({node->right, level + 1});
        }
    }
    return V;
}