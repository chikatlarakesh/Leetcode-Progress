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
    TreeNode* constructBT(vector<int>& postorder,int postStart,int postEnd, vector<int>& inorder,int inStart,int inEnd, unordered_map<int,int>& inorderMap)
    {
        if(postStart>postEnd || inStart>inEnd) return NULL;

        TreeNode* root= new TreeNode(postorder[postEnd]);
        int inorderRoot= inorderMap[root->val];
        int numsRight= inEnd-inorderRoot;

        root->left = constructBT(postorder,postStart,postEnd-numsRight-1,inorder,inStart,inorderRoot-1,inorderMap);
        root->right= constructBT(postorder,postEnd-numsRight,postEnd-1,inorder,inorderRoot+1,inEnd,inorderMap);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inorderMap;
        int n=inorder.size();
        for(int i=0;i<n;i++) inorderMap[inorder[i]]=i;

        TreeNode* root= constructBT(postorder,0,n-1,inorder,0,n-1,inorderMap);
        return root;
    }
};