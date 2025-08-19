class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1]) count++;
            if(count>=2) return false;
        }
        if(count==1 && nums[n-1]>nums[0]) return false;
        return true;
    }
};