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
    TreeNode* findRightmostNode(TreeNode* root)
    {
        while(root != NULL && root->right != NULL) root = root->right;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        TreeNode* leftNode = root->left;
        TreeNode* rightNode = root->right;

        if(root->val < key) root->right = deleteNode(root->right,key);
        else if(root->val > key) root->left = deleteNode(root->left,key);
        else
        {
            // 0 children
            if(root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            // 1 child
            else if(root->left == NULL || root->right == NULL)
            {
                if(root->left)
                {
                    delete root;
                    return leftNode;
                }
                else
                {
                    delete root;
                    return rightNode;
                }
            }
            // 2 children
            else
            {
                // find rightmost node
                TreeNode* IP = findRightmostNode(leftNode);
                IP->right = rightNode;
                delete root;
                return leftNode;
            }
        }
        return root;
    }
};