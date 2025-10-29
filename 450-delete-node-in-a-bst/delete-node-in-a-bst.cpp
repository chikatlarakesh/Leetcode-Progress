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
    TreeNode* findRight(TreeNode* root) {
        if(root->right == NULL) return root;
        return findRight(root->right);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        
        if(root->val == key) {
            if(root->left) {
                TreeNode* bottomRight = findRight(root->left);
                bottomRight->right = root->right;
                TreeNode* newRoot = root->left;
                delete root;
                return newRoot;
            }
            else {
                TreeNode* newRoot = root->right;
                delete root;
                return newRoot;
            }
        }
        else if(root->val > key) {
            root->left = deleteNode(root->left,key);
        }
        else root->right = deleteNode(root->right,key);
        return root;
    }
};