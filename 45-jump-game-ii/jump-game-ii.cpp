class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return 0;
        int steps=nums[0],maxReach=nums[0],minJumps=1;
        for(int i=1;i<n;i++)
        {
            if(i==n-1) return minJumps;
            maxReach=max(maxReach,i+nums[i]);
            steps--;
            if(steps==0)
            {
                minJumps++;
                steps=maxReach-i;
            }
        }
        return minJumps;
    }
};