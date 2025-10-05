class Solution {
public:
    string removeSubstring(string s, int k) {
        int n = s.length();
        stack<pair<char,int>> st;
        for(char ch: s) {
            if(!st.empty() && st.top().first == ch) {
                st.top().second++;
            }
            else st.push({ch,1});

            if(st.size() >= 2) {
                auto closing = st.top();
                st.pop();
                auto opening = st.top();
                st.pop();

                if((closing.first == ')' && closing.second == k) &&
                    (opening.first == '(' && opening.second >= k)) {
                        opening.second -= k;
                        if(opening.second > 0) {
                            st.push(opening);
                        }
                }
                else {
                    st.push(opening);
                    st.push(closing);
                }
            }
        }

        string result = "";
        while(!st.empty()) {
            char bracket = st.top().first;
            int count = st.top().second;
            st.pop();
            while(count--) {
                result += bracket;
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};