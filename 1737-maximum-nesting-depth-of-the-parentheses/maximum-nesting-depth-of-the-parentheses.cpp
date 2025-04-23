class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();
        int i,result=0,count=0;
        stack<char> st;
        for(i=0;i<n;i++)
        {
            if(s[i]=='(') 
            {
                st.push(s[i]);
                count++;
            }
            else if(s[i]==')' && st.top()=='(')
            {
                st.pop();
                count--;
            }
            result=max(result,count);
        }
        return result;
    }
};