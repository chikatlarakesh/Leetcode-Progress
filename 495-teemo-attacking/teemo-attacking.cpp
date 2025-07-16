class Solution {
public:
    int findPoisonedDuration(vector<int>& nums, int duration) {
        int n=nums.size();
        int totalSeconds=duration,difference=0;
        for(int i=0;i<n-1;i++)
        {
            difference=nums[i+1]-nums[i];
            totalSeconds+=min(difference, duration);
        }
        return totalSeconds;
    }
};