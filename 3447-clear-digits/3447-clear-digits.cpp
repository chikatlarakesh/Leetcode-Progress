class Solution {
public:
    string clearDigits(string s) {
        int n=s.length();
        stack<char> st;
        int i;
        for(i=0;i<n;i++)
        {
            if(isalpha(s[i]))
            {
                st.push(s[i]);
            }
            else if(isdigit(s[i]))
            {
                st.pop();
            }
        }
        s="";
        while(!st.empty())
        {
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};