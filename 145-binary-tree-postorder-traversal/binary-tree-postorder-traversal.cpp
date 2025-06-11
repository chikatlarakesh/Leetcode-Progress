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
    // void postOrder(TreeNode* root,vector<int>& result)
    // {
    //     if(root==nullptr) return;
    //     postOrder(root->left,result);
    //     postOrder(root->right,result);
    //     result.push_back(root->val);
    // }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root==NULL) return result;
        stack<TreeNode*> st;
        TreeNode* curr=root;
        TreeNode* temp=nullptr;

        while(curr!=NULL || !st.empty())
        {
            if(curr!=NULL)
            {
                st.push(curr);
                curr=curr->left;
            }
            else
            {
                temp=st.top()->right;
                if(temp==NULL)
                {
                    temp=st.top();
                    st.pop();
                    result.push_back(temp->val);
                    while(!st.empty() && temp==st.top()->right)
                    {
                        temp=st.top();
                        st.pop();
                        result.push_back(temp->val);
                    }
                }
                else curr=temp;
            }
        }
        return result;

        // vector<int> result;
        // postOrder(root,result);
        // return result;



        // vector<int> result;
        // if(root==NULL) return result;
        // stack<TreeNode*> s1;
        // s1.push(root);
        // stack<TreeNode*> s2;
        // TreeNode* node=root;
        // while(true)
        // {
        //     if(s1.empty()) break;
        //     node=s1.top();
        //     s1.pop();
        //     s2.push(node);
        //     if(node->left) s1.push(node->left);
        //     if(node->right) s1.push(node->right);
        // }
        // while(!s2.empty())
        // {
        //     result.push_back(s2.top()->val);
        //     s2.pop();
        // }
        // return result;
    }
};