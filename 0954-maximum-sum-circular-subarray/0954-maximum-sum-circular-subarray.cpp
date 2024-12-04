class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int i,sum=0,mintemp=0,minn=nums[0],maxtemp=0,maxx=nums[0];
        for(i=0;i<n;i++)
        {
            sum=sum+nums[i];
            mintemp=min(mintemp+nums[i],nums[i]);
            minn=min(minn,mintemp);
            maxtemp=max(maxtemp+nums[i],nums[i]);
            maxx=max(maxx,maxtemp);
        }
        if(maxx>0)
        {
            return max(maxx,sum-minn);
        }
        return maxx;
    }
};