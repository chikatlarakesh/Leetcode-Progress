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
    TreeNode* curr;

    void pushAllLeft(TreeNode* root) {
        while(root) {
            st.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        pushAllLeft(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }


    // int i = 0;
    // vector<int> inorder;

    // void inorderTraversal(TreeNode* root)
    // {
    //     if(root == NULL) return;

    //     inorderTraversal(root->left);
    //     inorder.push_back(root->val);
    //     inorderTraversal(root->right);
    // }

    // BSTIterator(TreeNode* root) {
    //     inorderTraversal(root);
    // }
    
    // int next() {
    //     int val = inorder[i];
    //     i++;
    //     return val;
    // }
    
    // bool hasNext() {
    //     if(i < inorder.size()) return true;
    //     return false;
    // }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */