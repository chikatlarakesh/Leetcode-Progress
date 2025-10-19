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
    using ll = long long;
    bool checkValid(ll left,ll right,TreeNode* root) {
        if(root == NULL) return true;

        if(root->val <= left || root->val >= right) return false;
        return checkValid(left,root->val,root->left) && checkValid(root->val,right,root->right);
    }

    bool isValidBST(TreeNode* root) {
        return checkValid(LLONG_MIN,LLONG_MAX,root);
    }
};