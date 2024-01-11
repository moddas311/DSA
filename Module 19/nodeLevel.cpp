#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        bool isOriginal;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int nodeLevel(TreeNode<int> *root, int searchedValue)
{
    // Write your code here.
    queue<pair<TreeNode<int> *, int>> Q;

    Q.push({root, 1});
    while (!Q.empty())
    {
        // 1. ber kore kothao rakha
        pair<TreeNode<int> *, int> parent = Q.front();
        TreeNode<int> *node = parent.first;
        int level = parent.second;
        Q.pop();

        // 2. jabotio sob kora
        if (node->val == searchedValue)
        {
            return level;
        }

        // 3. children push kora
        if (node->left)
        {
            Q.push({node->left, level + 1});
        }

        if (node->right)
        {
            Q.push({node->right, level + 1});
        }
    }
}
