class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> leftSuffix(n);
        vector<int> rightSuffix(n);
        leftSuffix[0]=height[0];
        rightSuffix[n-1]=height[n-1];
        for(int i=1;i<n;i++)
        {
            leftSuffix[i]=max(leftSuffix[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            rightSuffix[i]=max(rightSuffix[i+1],height[i]);
        }
        int units=0;
        for(int i=0;i<n;i++)
        {
            int small=min(leftSuffix[i],rightSuffix[i]);
            units+=small-height[i];
        }
        return units;
    }
};