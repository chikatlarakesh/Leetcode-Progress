class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int> mp;
        unordered_set<char> letters;
        stack<char> st;
        for(char ch:s)
        {
            mp[ch]++;
        }
        for(char ch: s)
        {
            mp[ch]--;
            if(letters.count(ch)) continue;
            while(!st.empty() && st.top()>ch && mp[st.top()]>0)
            {
                letters.erase(st.top());
                st.pop();
            }
            st.push(ch);
            letters.insert(ch);
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