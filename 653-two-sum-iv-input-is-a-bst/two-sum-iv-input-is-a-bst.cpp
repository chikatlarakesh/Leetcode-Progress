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
class BSTIterator {
public:
    stack<TreeNode*> st;
    bool reverse;

    void pushAll(TreeNode* root,bool isReverse) {
        while(root) {
            st.push(root);
            if(!isReverse) root = root->left;
            else root = root->right;
        }
    }

    BSTIterator(TreeNode* root,bool isReverse) {
        reverse = isReverse;
        pushAll(root,reverse);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        if(!reverse) pushAll(node->right,reverse);
        else pushAll(node->left,reverse);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator left(root,false);
        BSTIterator right(root,true);

        int i = left.next();
        int j = right.next();
        while(i < j) {
            if(i+j == k) return true;
            else if(i+j > k) j = right.next();
            else i = left.next();
        }
        return false;
    }



    // bool checkIfExist(TreeNode* root,unordered_set<int>& s,int k)
    // {
    //     if(root == NULL) return false;
    //     if(s.find(k - root->val) != s.end()) return true;

    //     s.insert(root->val);
    //     return checkIfExist(root->left,s,k) || checkIfExist(root->right,s,k);
    // }

    // bool findTarget(TreeNode* root, int k) {
    //     unordered_set<int> s;
    //     return checkIfExist(root,s,k);
    // }
};