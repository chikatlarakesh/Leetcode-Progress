class Solution {
public:
    string makeGood(string s) {
        int n=s.length();
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            if(st.empty())
            {
                st.push(s[i]);
            }
            else if(ch+32==st.top() || ch-32==st.top())
            {
                st.pop();
            }
            else st.push(s[i]);
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};