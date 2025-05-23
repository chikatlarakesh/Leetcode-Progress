class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int maxProfit=0;
        unordered_map<int,int> mp;
        int n=profit.size();
        int m=worker.size();
        for(int i=0;i<n;i++)
        {
            if(mp.find(profit[i])!=mp.end())
            {
                int prevElement=mp[profit[i]]; 
                int newElement=min(mp[profit[i]],difficulty[i]);
                mp[profit[i]]=newElement;
            }
            else mp[profit[i]]=difficulty[i];
        }
        sort(profit.begin(),profit.end(),greater<int>());
        sort(worker.begin(),worker.end(),greater<int>());
        int i=0,j=0;
        while(i<n && j<m)
        {
            if(mp[profit[i]]<=worker[j])
            {
                maxProfit+=profit[i];
                j++;
            }
            else i++;
        }
        return maxProfit;
    }
};