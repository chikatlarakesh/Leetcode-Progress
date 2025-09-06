class Solution {
public:
    bool wildcardMatching(int i,int j,string& s,string& p,vector<vector<int>>& dp)
    {
        if(i<0 && j<0) return true;
        if(j<0) return false;
        if(i<0)
        {
            int k=j;
            while(k>=0)
            {
                if(p[k]!='*') return false;
                k--;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        bool match=false, notMatch=false;
        if(s[i]==p[j]) match=wildcardMatching(i-1,j-1,s,p,dp);
        else
        {
            if(p[j]=='?') notMatch=wildcardMatching(i-1,j-1,s,p,dp);
            else if(p[j]=='*') notMatch= (wildcardMatching(i,j-1,s,p,dp) || wildcardMatching(i-1,j-1,s,p,dp) || wildcardMatching(i-1,j,s,p,dp));
            else return false;
        }

        return dp[i][j]=(match || notMatch);
    }

    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return wildcardMatching(n-1,m-1,s,p,dp);
    }
};