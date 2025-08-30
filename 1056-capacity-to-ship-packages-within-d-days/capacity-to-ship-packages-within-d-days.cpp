class Solution {
public:
    bool isPossible(int capacity,vector<int>& nums,int maxDays)
    {
        int currWeight=0,totalDays=1;
        for(int num:nums)
        {
            if(num>capacity) return false;
            if(currWeight+num>capacity)
            {
                totalDays++;
                currWeight=0;
            }
            currWeight+=num;
        }
        return totalDays<=maxDays;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();

        int low=1;
        int high=1e9;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isPossible(mid,weights,days)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};