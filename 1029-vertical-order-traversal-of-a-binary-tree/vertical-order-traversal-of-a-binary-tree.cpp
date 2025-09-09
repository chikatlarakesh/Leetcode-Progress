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
    class comparer
    {
        public:
        bool operator()(pair<int,int>& a,pair<int,int>& b)
        {
            if(a.first==b.first) return a.second<b.second;
            return a.first<b.first;
        }
    };

    void verticalOrderTraversal(int row,int col,TreeNode* root,map<int,vector<pair<int,int>>>& mp)
    {
        if(root==NULL) return;

        mp[col].push_back({row,root->val});
        verticalOrderTraversal(row+1,col-1,root->left,mp);
        verticalOrderTraversal(row+1,col+1,root->right,mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL) return result;
        map<int,vector<pair<int,int>>> mp;
        verticalOrderTraversal(0,0,root,mp);

        for(auto &[col,nodes]: mp)
        {
            sort(nodes.begin(),nodes.end(),comparer());
            vector<int> arr;
            for(auto &[row,value]: nodes)
            {
                arr.push_back(value);
            }
            result.push_back(arr);
        }
        return result;
    }
};