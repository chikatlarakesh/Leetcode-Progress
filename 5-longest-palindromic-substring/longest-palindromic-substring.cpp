class Solution {
public:
    bool checkPalindrome(int i,int j,string& s,vector<vector<int>>& dp)
    {
        if(i>=j) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==s[j]) return dp[i][j]=checkPalindrome(i+1,j-1,s,dp);
        return dp[i][j]=false;
    }

    string longestPalindrome(string s) {
        int n=s.length();

        vector<vector<int>> dp(n,vector<int>(n,-1));
        int maxLen=0,startingPoint=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(checkPalindrome(i,j,s,dp)==true)
                {
                    if(j-i+1>maxLen)
                    {
                        maxLen=j-i+1;
                        startingPoint=i;
                    }
                }
            }
        }
        return s.substr(startingPoint,maxLen);
    }
};