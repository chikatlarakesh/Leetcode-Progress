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
    void zigzag(TreeNode* root,vector<vector<int>>& result)
    {
        if(root==NULL) return;

        queue<TreeNode*> q;
        q.push(root);
        bool flag=true;
        while(!q.empty())
        {
            int n=q.size();

            vector<int> arr;
            for(int i=0;i<n;i++)
            {
                TreeNode* node= q.front();
                q.pop();
                int val=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                arr.push_back(val);    
            }
            if(!flag) reverse(arr.begin(),arr.end());
            result.push_back(arr);
            flag=!flag;
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL) return result;
        zigzag(root,result);
        return result;
    }
};