class Solution {
public:
    bool isPossible(int speed,vector<int>& nums,int maxTime)
    {
        int n=nums.size();
        int totalTime=0;
        for(int i=0;i<n;i++)
        {
            totalTime+=nums[i]/speed;
            if(nums[i]%speed!=0) totalTime++;
            if(totalTime>maxTime) return false;
        }
        return true;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1,high=*max_element(piles.begin(),piles.end());
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isPossible(mid,piles,h)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};