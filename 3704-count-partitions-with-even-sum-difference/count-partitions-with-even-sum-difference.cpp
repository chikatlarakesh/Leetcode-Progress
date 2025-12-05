class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        int currSum=0,count=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            currSum+=nums[i];
            int remSum=abs(totalSum-currSum);
            int temp=abs(currSum-remSum);
            if(temp%2==0) count++;
        }
        return count;
    }
};