class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth=0;
        int n=accounts.size();
        int m=accounts[0].size();
        for(int i=0;i<n;i++)
        {
            int currSum=0;
            for(int j=0;j<m;j++)
            {
                currSum+=accounts[i][j];
            }
            maxWealth=max(maxWealth,currSum);
        }
        return maxWealth;
    }
};