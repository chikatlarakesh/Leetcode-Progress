class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        if(k>=n) return "0";
        stack<char> st;
        int i=0;
        while(i<n)
        {
            int val=num[i]-'0';
            while(!st.empty() && k>0 && st.top()>val)
            {
                st.pop();
                k--;
            }
            st.push(val);
            i++;
        }
        string result="";
        while(!st.empty())
        {
            while(k>0)
            {
                st.pop();
                k--;
            }
            result+=st.top()+'0';
            st.pop();
        }
        reverse(result.begin(),result.end());
        n=result.length();
        string ans="";
        i=0;
        while(i<n)
        {
            if(result[i]=='0' && ans.length()==0) 
            {
                i++;
                continue;
            }
            ans+=result[i];
            i++;
        }
        if(ans.length()==0) return "0";
        return ans;
    }
};