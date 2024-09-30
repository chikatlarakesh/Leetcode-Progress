int countGoodSubstrings(string s) {
        int n=s.length();
        map<char,int> map;
        int count=0;
        int result=0;
        int l=0;
        int r=0;
        for(r=0;r<n;r++)
        {
            map[s[r]]++;
            if(r-l+1==3)
            {
                if(map.size()==3)
                {
                    result++;
                }
                map[s[l]]--;
                if(map[s[l]]==0)
                {
                    map.erase(s[l]);
                }
                l++;
            }
        }
        return result;
    }
