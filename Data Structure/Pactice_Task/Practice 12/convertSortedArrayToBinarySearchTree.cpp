/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.empty())
            return nullptr;
        int middle = nums.size() / 2;
        TreeNode *root = new TreeNode(nums[middle]);

        vector<int> leftRoot(nums.begin(), nums.begin() + middle);
        vector<int> rightRoot(nums.begin() + middle + 1, nums.end());

        root->left = sortedArrayToBST(leftRoot);
        root->right = sortedArrayToBST(rightRoot);
        return root;
    }
};