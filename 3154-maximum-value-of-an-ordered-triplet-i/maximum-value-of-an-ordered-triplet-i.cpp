class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long result=0;
        long long i,j,k;
        for(i=0;i<n-2;i++)
        {
            for(j=i+1;j<n-1;j++)
            {
                for(k=j+1;k<n;k++)
                {
                    long long val=(long long)(nums[i]-nums[j])* nums[k];
                    result=max(result,val);
                }
            }
        }
        return result;
    }
};