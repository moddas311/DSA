/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution
{
public:
    vector<int> v;

    void pushNode(TreeNode *root)
    {
        if (!root)
            return;

        v.push_back(root->val);
        pushNode(root->left);
        pushNode(root->right);
    }
    bool findTarget(TreeNode *root, int k)
    {
        pushNode(root);
        int len = v.size();
        bool found = false;

        for (int i = 0; i < len - 1; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (v[i] + v[j] == k)
                {
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }
        return found;
    }
};
