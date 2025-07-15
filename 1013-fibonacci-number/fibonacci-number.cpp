class Solution {
public:
    int fib(int n) {
        // if(n<=1) return n;
        // vector<int> dp(n+1,-1);
        // dp[0]=0;
        // dp[1]=1;
        
        // for(int i=2;i<=n;i++)
        // {
        //     dp[i]=dp[i-1]+dp[i-2];
        // }
        // return dp[n];

        int curr=0,prev=1,prev2=0;
        if(n==1) return prev;
        for(int i=2;i<=n;i++)
        {
            curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return curr;
    }
};