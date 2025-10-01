class Solution {
public:
    class comparer {
        public:
        bool operator()(const string& a,const string& b) {
            if(a.length() != b.length()) {
                return a.length() < b.length();
            }
            return a < b;
        }
    };

    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comparer());
        unordered_map<string,int> mp;
        int n = words.size();
        int maxLength = 0;

        for(int i=0;i<n;i++) {
            int m = words[i].length();
            int length = 1;
            for(int j=0;j<m;j++) {
                string s = words[i];
                s.erase(j,1);
                if(mp.find(s) != mp.end()) {
                    int currLength = mp[s];
                    if(currLength + 1 > length) {
                        length = currLength + 1;
                    }
                }
            }
            maxLength = max(maxLength,length);
            mp[words[i]] = length;
        }
        return maxLength;
    }
};