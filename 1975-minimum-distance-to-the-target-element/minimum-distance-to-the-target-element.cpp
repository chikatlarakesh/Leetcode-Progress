class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minDistance=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target)
            {
                minDistance=min(minDistance,abs(i-start));
            }
        }
        return minDistance;
    }
};