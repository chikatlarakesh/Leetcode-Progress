class Solution {
public:
    bool isPalindrome(string s,int l,int r)
    {
        while(l<r)
        {
            if(s[l]!=s[r])
            {
                return false;
            }
            else
            {
                l++;
                r--;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n=s.size();
        int l=0;
        int r=n-1;
        while(l<r)
        {
            if(s[l]==s[r])
            {
                l++;
                r--;
            }
            else
            {
                if(!isPalindrome(s,l+1,r) && !isPalindrome(s,l,r-1))
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
        }
        return true;
    }
};