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
    int findLeftHeight(TreeNode* root)
    {
        int height=0;
        while(root)
        {
            height++;
            root=root->left;
        }
        return height;
    }

    int findRightHeight(TreeNode* root)
    {
        int height=0;
        while(root)
        {
            height++;
            root=root->right;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;

        int left=findLeftHeight(root);
        int right=findRightHeight(root);

        if(left==right) return pow(2,left) - 1;
        else return 1 + countNodes(root->left) + countNodes(root->right);


        // if(root==NULL) return 0;

        // int left=countNodes(root->left);
        // int right=countNodes(root->right);

        // return 1+(left+right);
    }
};