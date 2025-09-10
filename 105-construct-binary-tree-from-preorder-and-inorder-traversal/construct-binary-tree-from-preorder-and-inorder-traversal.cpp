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
    TreeNode* constructBT(vector<int>& preorder,int preStart,int preEnd, vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int>& inorderMap)
    {
        if(preStart>preEnd || inStart>inEnd) return NULL;

        TreeNode* root=new TreeNode(preorder[preStart]);

        int inorderRoot= inorderMap[root->val];
        int numsLeft=inorderRoot-inStart;

        root->left= constructBT(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inorderRoot-1,inorderMap);

        root->right= constructBT(preorder,preStart+numsLeft+1,preEnd,inorder,inorderRoot+1,inEnd,inorderMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inorderMap;
        int n=inorder.size();
        for(int i=0;i<n;i++) inorderMap[inorder[i]]=i;

        TreeNode* root= constructBT(preorder,0,n-1,inorder,0,n-1,inorderMap);
        return root;
    }
};