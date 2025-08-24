class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.length();
        vector<int> sMap(256,-1),tMap(256,-1);

        for(int i=0;i<n;i++)
        {
            if((sMap[s[i]]!=-1 || tMap[t[i]]!=-1) &&
                (sMap[s[i]]!=t[i] || tMap[t[i]]!=s[i])) return false;
            sMap[s[i]]=t[i];
            tMap[t[i]]=s[i];
        }
        return true;
    }
};