class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> rightSuffix(n);
        int leftMax=height[0];
        rightSuffix[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rightSuffix[i]=max(rightSuffix[i+1],height[i]);
        }
        int units=0;
        for(int i=0;i<n;i++)
        {
            leftMax=max(leftMax,height[i]);
            int small=min(leftMax,rightSuffix[i]);
            units+=small-height[i];
        }
        return units;
    }
};