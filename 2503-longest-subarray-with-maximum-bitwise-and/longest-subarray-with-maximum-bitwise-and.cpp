class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxVal=*max_element(nums.begin(),nums.end());

        int count=0,maxLen=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==maxVal)
            {
                count++;
                maxLen=max(maxLen,count);
            }
            else count=0;
        }
        return maxLen;
    }
};