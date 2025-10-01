class Solution {
public:
    // MY APPROACH
    class comparer {
        public:
        bool operator()(const string& a,const string& b) const {
            if(a.length() != b.length()) {
                return a.length() < b.length();
            }
            return a < b;
        }
    };

    // int longestStrChain(vector<string>& words) {
    //     sort(words.begin(),words.end(),comparer());
    //     unordered_map<string,int> mp;
    //     int n = words.size();
    //     int maxLength = 0;

    //     for(int i=0;i<n;i++) {
    //         int m = words[i].length();
    //         int length = 1;
    //         for(int j=0;j<m;j++) {
    //             string s = words[i];
    //             s.erase(j,1);
    //             if(mp.find(s) != mp.end()) {
    //                 int currLength = mp[s];
    //                 if(currLength + 1 > length) {
    //                     length = currLength + 1;
    //                 }
    //             }
    //         }
    //         maxLength = max(maxLength,length);
    //         mp[words[i]] = length;
    //     }
    //     return maxLength;
    // }

    // STRIVER APPROACH

    bool isPossible(string& s1,string& s2) {
        if(s1.length() != s2.length() + 1) return false;

        int i = 0, j = 0;
        while(i < s1.length()) {
            if(s1[i] == s2[j]) {
                i++;
                j++;
            }
            else {
                i++;
            }
        }
        return (i == s1.length() && j == s2.length());
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comparer());
        int n = words.size();
        vector<int> dp(n,1);
        int maxLength = 0;

        for(int i=0;i<n;i++) {
            for(int prevInd = 0;prevInd<i;prevInd++) {
                if(isPossible(words[i],words[prevInd]) && dp[prevInd] + 1 > dp[i]) {
                    dp[i] = dp[prevInd] + 1;
                }
            }
            maxLength = max(maxLength,dp[i]);
        }
        return maxLength;
    }
};