class Solution {
public:
    int calcMaxProfit(vector<pair<int,int>>& nums,int target,int l,int r)
    {
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(nums[m].first<=target)
            {
                l=m+1;
            }
            else r=m-1;
        }
        if(r<0) return 0;
        if(nums[r].first>target) return nums[l].second;
        return nums[r].second;
    }


    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int maxProfit=0;
        vector<pair<int,int>> combArray;
        int n=difficulty.size();
        for(int i=0;i<n;i++)
        {
            combArray.push_back({difficulty[i],profit[i]});
        }
        sort(combArray.begin(),combArray.end());
        int maxi=combArray[0].second;
        for(int i=1;i<n;i++)
        {
            maxi=max(maxi,combArray[i].second);
            combArray[i].second=maxi;
        }
        int m=worker.size();
        for(int i=0;i<m;i++)
        {
            maxProfit+=calcMaxProfit(combArray,worker[i],0,n-1);
        }
        return maxProfit;













        // int maxProfit=0;
        // unordered_map<int,int> mp;
        // int n=profit.size();
        // int m=worker.size();
        // for(int i=0;i<n;i++)
        // {
        //     if(mp.find(profit[i])!=mp.end())
        //     {
        //         int prevElement=mp[profit[i]]; 
        //         int newElement=min(mp[profit[i]],difficulty[i]);
        //         mp[profit[i]]=newElement;
        //     }
        //     else mp[profit[i]]=difficulty[i];
        // }
        // sort(profit.begin(),profit.end(),greater<int>());
        // sort(worker.begin(),worker.end(),greater<int>());
        // int i=0,j=0;
        // while(i<n && j<m)
        // {
        //     if(mp[profit[i]]<=worker[j])
        //     {
        //         maxProfit+=profit[i];
        //         j++;
        //     }
        //     else i++;
        // }
        // return maxProfit;
    }
};