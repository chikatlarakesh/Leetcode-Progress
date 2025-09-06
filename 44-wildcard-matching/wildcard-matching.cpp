class Solution {
public:

    // MEMOIZATION
    // bool wildcardMatching(int i,int j,string& s,string& p,vector<vector<int>>& dp)
    // {
    //     if(i<0 && j<0) return true;
    //     if(j<0) return false;
    //     if(i<0)
    //     {
    //         int k=j;
    //         while(k>=0)
    //         {
    //             if(p[k]!='*') return false;
    //             k--;
    //         }
    //         return true;
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];

    //     if(s[i]==p[j] || p[j]=='?') return dp[i][j]= wildcardMatching(i-1,j-1,s,p,dp);
    //     if(p[j]=='*') return dp[i][j]= (wildcardMatching(i,j-1,s,p,dp) || wildcardMatching(i-1,j,s,p,dp));

    //     return dp[i][j]= false;
    // }

    // bool isMatch(string s, string p) {
    //     int n=s.length();
    //     int m=p.length();
    //     vector<vector<int>> dp(n,vector<int>(m,-1));
    //     return wildcardMatching(n-1,m-1,s,p,dp);
    // }


    // TABULATION
    // bool isMatch(string s, string p) {
    //     int n=s.length();
    //     int m=p.length();
    //     vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
    //     for(int i=0;i<=n;i++)
    //     {
    //         for(int j=0;j<=m;j++)
    //         {
    //             if(i==0 && j==0) dp[i][j]=true;
    //             else if(j==0) dp[i][j]=false;
    //             else if(i==0)
    //             {
    //                 bool flag=true;
    //                 int k=j;
    //                 while(k>=1)
    //                 {
    //                     if(p[k-1]!='*')
    //                     {
    //                         flag=false;
    //                         dp[i][j]=false;
    //                     }
    //                     k--;
    //                 }
    //                 if(flag) dp[i][j]=true;
    //             }
    //             else
    //             {
    //                 if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j]= dp[i-1][j-1];
    //                 else if(p[j-1]=='*') dp[i][j]= (dp[i][j-1] || dp[i-1][j]);
    //                 else dp[i][j]= false;
    //             }
    //         }
    //     }
    //     return dp[n][m];
    // }


    // SPACE OPTIMIZATION
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<int> curr(m+1,-1), prev(m+1,-1);

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 && j==0) curr[j]=true;
                else if(j==0) curr[j]=false;
                else if(i==0)
                {
                    bool flag=true;
                    int k=j;
                    while(k>=1)
                    {
                        if(p[k-1]!='*')
                        {
                            flag=false;
                            curr[j]=false;
                        }
                        k--;
                    }
                    if(flag) curr[j]=true;
                }
                else
                {
                    if(s[i-1]==p[j-1] || p[j-1]=='?') curr[j]= prev[j-1];
                    else if(p[j-1]=='*') curr[j]= (curr[j-1] || prev[j]);
                    else curr[j]= false;
                }
            }
            prev=curr;
        }
        return curr[m];
    }
};