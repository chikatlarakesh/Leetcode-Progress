class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        if(k>=n) return "0";
        stack<char> st;
        int i=0;
        while(i<n)
        {
            while(!st.empty() && k>0 && (st.top()-'0')>(num[i]-'0'))
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
            i++;
        }
        string result="";
        while(!st.empty() && k>0)
        {
            st.pop();
            k--;
        }
        while(!st.empty())
        {
            result+=st.top();
            st.pop();
        }
        while(result.size()!=0 && result.back()=='0')
        {
            result.pop_back();
        }
        reverse(result.begin(),result.end());
        if(result.empty()) return "0";
        return result;
    }
};