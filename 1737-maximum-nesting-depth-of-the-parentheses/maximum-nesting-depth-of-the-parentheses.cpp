class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int maxDepth=0;
        for(char ch:s)
        {
            if(ch=='(') st.push(ch);
            else if(ch==')') st.pop();
            maxDepth=max(maxDepth,(int)st.size());
        }
        return maxDepth;
    }
};