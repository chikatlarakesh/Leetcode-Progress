class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0,maxLen=0;
        for(int num:nums)
        {
            if(num==0) count=0;
            else count++;
            maxLen=max(maxLen,count);
        }
        return maxLen;
    }
};