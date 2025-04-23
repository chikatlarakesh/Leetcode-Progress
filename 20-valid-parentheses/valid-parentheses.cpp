class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n=s.length();
        int i;
        for(i=0;i<n;i++)
        {
            if(s[i]=='(') st.push(s[i]);
            else if(s[i]=='{') st.push(s[i]);
            else if(s[i]=='[') st.push(s[i]);
            else if(st.empty()) return false;
            else if(s[i]==')' && !st.empty() && st.top()!='(') return false;
            else if(s[i]=='}' && !st.empty() && st.top()!='{') return false;
            else if(s[i]==']' && !st.empty() && st.top()!='[') return false;
            else st.pop();
        }
        if(st.empty()) return true;
        return false;
    }
};