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
class Solution {
public:
    int checkBalanced(TreeNode* root)
    {
        if(root==NULL) return 0;

        int left= checkBalanced(root->left);
        if(left == -1) return left;
        int right = checkBalanced(root->right);
        if(right == -1) return right;

        if(abs(left-right)>1) return -1;
        return 1 + max(left,right);
    }

    bool isBalanced(TreeNode* root) {
        if(checkBalanced(root) == -1) return false;
        return true;
    }
};