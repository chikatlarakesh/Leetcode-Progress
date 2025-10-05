class Solution {
public:
    bool isPalindrome(int i,int j,string& s) {
        while(i<j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    // int minimumCuts(int i,int n,string& s,vector<int>& dp) {
    //     if(i == n) return 0;
    //     if(dp[i] != -1) return dp[i];

    //     int minCuts = INT_MAX;
    //     for(int j=i;j<n;j++) {
    //         if(isPalindrome(i,j,s)) {
    //             int cuts = 1 + minimumCuts(j+1,n,s,dp);
    //             minCuts = min(minCuts,cuts);
    //         }
    //     }
    //     return dp[i] = minCuts;
    // }

    // int minCut(string s) {
    //     int n = s.length();
    //     vector<int> dp(n,-1);
    //     return minimumCuts(0,n,s,dp) - 1;
    // }

    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1,0);
        
        for(int i=n-1;i>=0;i--) {
            int minCuts = INT_MAX;
            for(int j=i;j<n;j++) {
                if(isPalindrome(i,j,s)) {
                    int cuts = 1 + dp[j+1];
                    minCuts = min(minCuts,cuts);
                }
            }
            dp[i] = minCuts;
        }
        return dp[0] - 1;
    }
};