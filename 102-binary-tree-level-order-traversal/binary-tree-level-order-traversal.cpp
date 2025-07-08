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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root==NULL) return res;
        q.push(root);
        while(q.size())
        {
            int n=q.size();
            vector<int> re;
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                re.push_back(temp->val);
                q.pop();
            }
            res.push_back(re);
        }
        return res;
    }
};