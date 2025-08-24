class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.length();
        vector<int> sMap(256,0),tMap(256,0);

        for(int i=0;i<n;i++)
        {
            if((sMap[s[i]]!=0 || tMap[t[i]]!=0) &&
                (sMap[s[i]]!=t[i]+1 || tMap[t[i]]!=s[i]+1)) return false;
            sMap[s[i]]=t[i]+1;
            tMap[t[i]]=s[i]+1;
        }
        return true;
    }
};