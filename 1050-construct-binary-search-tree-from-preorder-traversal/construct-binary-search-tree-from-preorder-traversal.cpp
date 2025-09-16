/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructBST(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int>& inorderMap) {
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inorderMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = constructBST(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,inorderMap);

        root->right = constructBST(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,inorderMap);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        vector<int> inorder(preorder.begin(),preorder.end());
        sort(inorder.begin(),inorder.end());
        unordered_map<int,int> inorderMap;
        for(int i=0;i<n;i++) inorderMap[inorder[i]] = i;

        return constructBST(preorder,0,n-1,inorder,0,n-1,inorderMap);
    }
};