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
    bool checkIfSame(TreeNode* p, TreeNode* q)
    {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;

        if(p->val!=q->val) return false;

        bool left= checkIfSame(p->left,q->left);
        if(!left) return false;
        bool right= checkIfSame(p->right,q->right);

        if(left && right) return true;
        return false;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return checkIfSame(p,q);
    }
};