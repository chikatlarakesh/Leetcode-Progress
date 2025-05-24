class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0,jumps=0;
        while(r<n-1)
        {
            int farthest=0;
            for(int i=l;i<=r;i++)
            {
                farthest=max(farthest,i+nums[i]);
            }
            l=r;
            r=farthest;
            jumps++;
        }
        return jumps;

        // if(n<=1) return 0;
        // int steps=nums[0],maxReach=nums[0],minJumps=1;
        // for(int i=1;i<n;i++)
        // {
        //     if(i==n-1) return minJumps;
        //     maxReach=max(maxReach,i+nums[i]);
        //     steps--;
        //     if(steps==0)
        //     {
        //         minJumps++;
        //         steps=maxReach-i;
        //     }
        // }
        // return minJumps;
    }
};