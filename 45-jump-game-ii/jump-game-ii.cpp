class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0,jumps=0;
        while(r<n-1)
        {
            int farthest=0; //ending range kanukotaniki
            for(int i=l;i<=r;i++)
            {
                farthest=max(farthest,i+nums[i]); // max entha dhooram ellagalav
            }
            l=r; //assigning r to l before modifying the value of r
            r=farthest; //assign r with the ending range
            jumps++; // increment jumps because that is the farthest we can reach
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