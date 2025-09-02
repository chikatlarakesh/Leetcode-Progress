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
    int getHeight(TreeNode* root)
    {
        if(root==NULL) return 0;

        int left=1+getHeight(root->left);
        int right=1+getHeight(root->right);

        return max(left,right);
    }

    bool isBalanced(TreeNode* root) {
        
        if(root==NULL) return true;

        int leftHeight=getHeight(root->left);
        int rightHeight=getHeight(root->right);

        if(abs(leftHeight-rightHeight)>1) return false;

        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);

        if(left==false || right==false) return false;
        return true;
    }
};