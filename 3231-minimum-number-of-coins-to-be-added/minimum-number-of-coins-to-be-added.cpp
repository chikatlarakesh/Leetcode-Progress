class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        int minCoins=0,curr=1;
        for(int i=0;i<n && curr<=target;i++)
        {
            if(curr==coins[i])
            {
                curr*=2;
            }
            else if(curr>coins[i])
            {
                curr+=coins[i];
            }
            else 
            {
                minCoins++;
                curr*=2;
                i--;
            }
        }
        while(curr<=target)
        {
            minCoins++;
            curr*=2;
        }
        return minCoins;
    }
};