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
    int maximumSum(TreeNode* root,int& maxi)
    {
        if(root==NULL) return 0;

        int left= maximumSum(root->left,maxi);
        if(left<0) left=0;
        int right=maximumSum(root->right,maxi);
        if(right<0) right=0;
        maxi=max(maxi,root->val+left+right);

        return root->val+ max(left,right);
    }

    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maximumSum(root,maxi);
        return maxi;
    }
};