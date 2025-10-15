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
    int maxi = 0;
    int findDiameter(TreeNode* root) {
        if(root == NULL) return 0;

        int left = findDiameter(root->left);
        int right = findDiameter(root->right);
        maxi = max(maxi,left+right+1);
        return 1 + max(left,right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        findDiameter(root);
        return maxi - 1;
    }
};