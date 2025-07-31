class Solution {
public:
    int minCost(int i,vector<int>& days,vector<int>& costs,vector<int>& dp)
    {
        if(i>=days.size()) return 0;
        if(i==days.size()-1)
        {
            return min({costs[0],costs[1],costs[2]});
        }
        if(dp[i]!=-1) return dp[i];

        int oneDay=costs[0]+minCost(i+1,days,costs,dp);
        int ending7Day=days[i]+7;
        int j=0;
        for(j=i;j<days.size();j++)
        {
            if(days[j]>=ending7Day) break;
        }
        int sevenDay=costs[1]+minCost(j,days,costs,dp);
        int ending30Day=days[i]+30;
        for(j=i;j<days.size();j++)
        {
            if(days[j]>=ending30Day) break;
        }
        int thirtyDay=costs[2]+minCost(j,days,costs,dp);
        return dp[i]=min({oneDay,sevenDay,thirtyDay});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n,-1);
        return minCost(0,days,costs,dp);
    }
};