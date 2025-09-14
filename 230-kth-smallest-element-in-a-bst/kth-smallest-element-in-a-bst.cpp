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
    void findKthSmallest(TreeNode* root,int k,int& count,int& ans)
    {
        if(root==NULL || ans!=-1) return;

        findKthSmallest(root->left,k,count,ans);
        count++;
        if(count==k)
        {
            ans = root->val; 
            return;
        }
        findKthSmallest(root->right,k,count,ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count=0,ans=-1;
        findKthSmallest(root,k,count,ans);
        return ans;

        // queue<TreeNode*> q;
        // priority_queue<int> pq;
        // q.push(root);
        // while(!q.empty())
        // {
        //     TreeNode* node = q.front();
        //     q.pop();
        //     pq.push(node->val);
        //     if(pq.size()>k) pq.pop();

        //     if(node->left) q.push(node->left);
        //     if(node->right) q.push(node->right);
        // }
        // return pq.top();
    }
};