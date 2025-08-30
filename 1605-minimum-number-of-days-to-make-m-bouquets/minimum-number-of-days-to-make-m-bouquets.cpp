class Solution {
public:
    bool isPossible(int days,vector<int>& nums,int boquets,int k)
    {
        int flowers=0;
        for(int num:nums)
        {
            if(num<=days) flowers++;
            else flowers=0;
            if(flowers==k)
            {
                boquets--;
                flowers=0;
            }
            if(boquets==0) return true;
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((n/k)<m) return -1;

        int low=1,high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isPossible(mid,bloomDay,m,k)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};