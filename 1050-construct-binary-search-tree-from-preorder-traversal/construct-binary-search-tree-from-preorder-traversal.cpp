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
    TreeNode* constructBST(int preStart,int preEnd,vector<int>& preorder,int inStart,int inEnd, vector<int>& inorder,unordered_map<int,int>& inorderMap) {

        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int index = inorderMap[root->val];
        int left = index - inStart;

        root->left = constructBST(preStart+1,preStart+left,preorder,inStart,index-1,inorder,inorderMap);

        root->right = constructBST(preStart+left+1,preEnd,preorder,index+1,inEnd,inorder,inorderMap);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        unordered_map<int,int> inorderMap;
        for(int i=0;i<n;i++) {
            inorderMap[inorder[i]] = i;
        }

        return constructBST(0,n-1,preorder,0,n-1,inorder,inorderMap);

    }
};