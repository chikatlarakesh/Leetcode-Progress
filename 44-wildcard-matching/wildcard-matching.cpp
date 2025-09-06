class Solution {
public:
    bool wildcardMatching(int i,int j,string& s,string& p,vector<vector<int>>& dp)
    {
        if(i<0 && j<0) return true;
        if(j<0) return false;
        if(i<0)
        {
            while(j>=0)
            {
                if(p[j]!='*') return false;
                j--;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==p[j] || p[j]=='?') return dp[i][j]= wildcardMatching(i-1,j-1,s,p,dp);
        if(p[j]=='*') return dp[i][j]= (wildcardMatching(i,j-1,s,p,dp) || wildcardMatching(i-1,j,s,p,dp));

        return dp[i][j]= false;
    }

    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return wildcardMatching(n-1,m-1,s,p,dp);
    }
};