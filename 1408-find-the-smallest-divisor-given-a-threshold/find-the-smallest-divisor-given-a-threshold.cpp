class Solution {
public:
    bool isPossible(int divisor,vector<int>& nums,int threshold)
    {
        int sum=0;
        for(int num:nums)
        {
            sum+=(num/divisor);
            if(num%divisor!=0) sum++;
        }
        if(sum<=threshold) return true;
        return false;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();

        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isPossible(mid,nums,threshold)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};