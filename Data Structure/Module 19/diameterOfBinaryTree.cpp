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

int mx = 0;

int maxHight(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int myLeft = maxHight(root->left);
    int myRight = maxHight(root->right);

    int diameter = myLeft + myRight;

    mx = max(mx, diameter);
    return max(myLeft, myRight) + 1;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    // Write Your Code Here.
    mx = 0;
    int h = maxHight(root);
    return mx;
}
