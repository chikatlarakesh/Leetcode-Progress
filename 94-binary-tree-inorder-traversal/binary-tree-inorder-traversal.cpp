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
    // void inOrder(TreeNode* root,vector<int>& result)
    // {
    //     if(root==nullptr) return;
    //     inOrder(root->left,result);
    //     result.push_back(root->val);
    //     inOrder(root->right,result);
    // }

    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> result;
        // inOrder(root,result);
        // return result;

        vector<int> result;
        if(root==nullptr) return result;
        stack<TreeNode*> st;
        TreeNode* node=root;
        while(true)
        {
            if(node!=NULL)
            {
                st.push(node);
                node=node->left;
            }
            else
            {
                if(st.empty()) break;
                node=st.top();
                st.pop();
                result.push_back(node->val);
                node=node->right;
            }
        }
        return result;
    }
};