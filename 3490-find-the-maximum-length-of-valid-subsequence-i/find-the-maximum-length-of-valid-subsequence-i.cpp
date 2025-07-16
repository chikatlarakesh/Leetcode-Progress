class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int maxLen=0;
        int oddCount=0,evenCount=0;
        for(int num:nums)
        {
            if(num%2==0) evenCount++;
            else oddCount++;
        }
        maxLen=max(evenCount,oddCount);

        int alternating=1,prev=nums[0]%2;
        for(int i=1;i<n;i++)
        {
            int curr=nums[i]%2;
            if(prev!=curr)
            {
                prev=curr;
                alternating++;
            }
        }
        return max(maxLen,alternating);
    }
};