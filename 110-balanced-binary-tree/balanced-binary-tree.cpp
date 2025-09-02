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

        int left=1+checkBalanced(root->left);
        int right=1+checkBalanced(root->right);

        if(abs(left-right)>1) return 6000;
        return max(left,right);
    }

    bool isBalanced(TreeNode* root) {
        if(checkBalanced(root)>=5000) return false;
        return true;
    }
};