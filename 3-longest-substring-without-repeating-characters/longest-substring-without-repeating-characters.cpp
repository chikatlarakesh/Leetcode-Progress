class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_set<char> set;
        int l=0,maxLen=0;
        for(int r=0;r<n;r++)
        {
            while(set.find(s[r])!=set.end())
            {
                set.erase(s[l]);
                l++;
            }
            set.insert(s[r]);
            maxLen=max(maxLen,(int)set.size());
        }
        return maxLen;
    }
};