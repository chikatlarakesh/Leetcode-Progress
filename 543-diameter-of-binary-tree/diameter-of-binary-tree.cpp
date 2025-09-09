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
    int maxDiameterOfTree(TreeNode* root,int& maxDiameter)
    {
        if(root==NULL) return 0;

        int left= maxDiameterOfTree(root->left,maxDiameter);
        int right=maxDiameterOfTree(root->right,maxDiameter);
        maxDiameter=max(maxDiameter,left+right);

        return 1+ max(left,right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int maxDiameter=0;
        maxDiameterOfTree(root,maxDiameter);
        return maxDiameter;
    }
};