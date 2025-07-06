class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        int totalCost=nums[0];
        int least=INT_MAX,secLeast=INT_MAX;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<least)
            {
                secLeast=least;
                least=nums[i];
            }
            else if(nums[i]<secLeast) secLeast=nums[i];
        }
        totalCost+=secLeast+least;
        return totalCost;
    }
};