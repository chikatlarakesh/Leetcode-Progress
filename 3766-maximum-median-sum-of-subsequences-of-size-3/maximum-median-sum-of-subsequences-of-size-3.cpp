class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long maxSum=0;
        int n=nums.size();
        int i=0,j=n-1;
        while(i<j)
        {
            maxSum+=nums[j-1];
            i++;
            j-=2;
        }
        return maxSum;
    }
};