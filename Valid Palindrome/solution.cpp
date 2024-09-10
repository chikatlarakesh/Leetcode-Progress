bool isPalindrome(string s) {
        string r="";
        int i;
        int n=s.length();
        for(i=0;i<n;i++)
        {
            if(isalnum(s[i]))
            {
                r+=tolower(s[i]);
            }
        }
        int m=r.length();
        for(i=0;i<m;i++)
        {
            if(r[i]!=r[m-i-1])
            {
                return false;
            }
        }
        return true;
    }
