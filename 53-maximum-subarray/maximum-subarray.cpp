class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();
        int maxSum=0,currSum=0,negMin=INT_MIN;
        for(int i=0;i<n;i++)
        {
            negMin=max(negMin,nums[i]);
            currSum+=nums[i];
            if(currSum<0) currSum=0;
            maxSum=max(maxSum,currSum);
        }
        if(maxSum==0) return negMin;
        return maxSum;
    }
};