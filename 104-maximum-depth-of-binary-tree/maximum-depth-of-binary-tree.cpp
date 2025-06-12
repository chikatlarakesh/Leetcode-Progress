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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
        // if(root==NULL) return 0;
        // queue<TreeNode*> q;
        // q.push(root);
        // int count=1;
        // bool present=false;
        // while(!q.empty())
        // {
        //     int n=q.size();
        //     present=false;
        //     for(int i=0;i<n;i++)
        //     {
        //         TreeNode* temp=q.front();
        //         if(temp->left) 
        //         {
        //             q.push(temp->left);
        //             present=true;
        //         }
        //         if(temp->right)
        //         {
        //             q.push(temp->right);
        //             present=true;
        //         }
        //         q.pop();
        //     }
        //     if(present) count++;
        // }
        // return count;
    }
};