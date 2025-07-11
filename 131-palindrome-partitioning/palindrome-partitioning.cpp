class Solution {
public:
    bool checkPalindrome(string s)
    {
        int n=s.length();
        int l=0,r=n-1;
        while(l<r) 
        {
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void palindromePartitioning(int ind,string s,int n,vector<string>& substrings,vector<vector<string>>& result)
    {
        if(ind==n)
        {
            result.push_back(substrings);
            return;
        }
        string ans="";
        for(int i=ind;i<n;i++)
        {
            ans+=s[i];
            if(checkPalindrome(ans))
            {
                substrings.push_back(ans);
                palindromePartitioning(i+1,s,n,substrings,result);
                substrings.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<string>> result;
        vector<string> substrings;
        palindromePartitioning(0,s,n,substrings,result);
        return result;
    }
};