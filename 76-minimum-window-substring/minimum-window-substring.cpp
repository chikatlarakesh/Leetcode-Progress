class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();
        unordered_map<char,int> mp;
        int r=0,count=0,minLen=INT_MAX,ind=-1,l=0;
        for(int i=0;i<m;i++) mp[t[i]]++;
        while(r<n)
        {
            if(mp[s[r]]>0) count++;
            mp[s[r]]--;
            while(count==m)
            {
                mp[s[l]]++;
                if(mp[s[l]]>0) count--;
                if(r-l+1<minLen)
                {
                    minLen=r-l+1;
                    ind=l;
                }
                l++;
            }
            r++;
        }
        if(ind==-1) return "";
        string ans=s.substr(ind,minLen);
        return ans;
    }
};