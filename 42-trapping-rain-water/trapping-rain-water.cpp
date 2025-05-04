class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftMax=0;
        int rightMax=0;
        int total=0;
        int l=0;
        int r=n-1;
        while(l<r)
        {
            if(height[l]<=height[r])
            {
                if(leftMax>height[l])
                {
                    total+=leftMax-height[l];
                }
                else leftMax=height[l];
                l++;
            }
            else
            {
                if(rightMax>height[r])
                {
                    total+=rightMax-height[r];
                }
                else rightMax=height[r];
                r--;
            }
        }
        return total;
        // int n=height.size();
        // vector<int> rightSuffix(n);
        // int leftMax=height[0];
        // rightSuffix[n-1]=height[n-1];
        // for(int i=n-2;i>=0;i--)
        // {
        //     rightSuffix[i]=max(rightSuffix[i+1],height[i]);
        // }
        // int units=0;
        // for(int i=0;i<n;i++)
        // {
        //     leftMax=max(leftMax,height[i]);
        //     int small=min(leftMax,rightSuffix[i]);
        //     units+=small-height[i];
        // }
        // return units;
    }
};