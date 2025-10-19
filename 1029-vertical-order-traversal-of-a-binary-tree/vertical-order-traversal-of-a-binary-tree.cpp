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
    class comparer {
        public:
        bool operator()(const pair<int,int>& a,const pair<int,int>& b) {
            if(a.first == b.first) return a.second < b.second;
            else return a.first < b.first;
        }
    };

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> mp;
        vector<vector<int>> result;

        using Node = pair<TreeNode*,pair<int,int>>;
        queue<Node> q;
        q.push({root,{0,0}});

        while(!q.empty()) {
            TreeNode* node = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            mp[col].push_back({row,node->val});

            if(node->left) {
                q.push({node->left,{row+1,col-1}});
            }
            if(node->right) {
                q.push({node->right,{row+1,col+1}});
            }
        }

        for(auto &it: mp) {
            auto &vec = it.second;
            sort(vec.begin(),vec.end(),comparer());
            vector<int> temp;
            for(auto &[row,val]: vec) temp.push_back(val);
            result.push_back(temp);
        }
        return result;
    }
};