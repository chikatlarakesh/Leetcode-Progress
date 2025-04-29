class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> prefixMax(n);
        vector<int> suffixMax(n);
        int leftMax=0,rightMax=0;
        prefixMax[0]=height[0];
        suffixMax[n-1]=height[n-1];
        for(int i=1;i<n;i++)
        {
            prefixMax[i]=max(prefixMax[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            suffixMax[i]=max(suffixMax[i+1],height[i]);
        }
        int result=0;
        for(int i=0;i<n;i++)
        {
            leftMax=prefixMax[i];
            rightMax=suffixMax[i];
            result+=min(leftMax,rightMax)-height[i];
        }
        return result;
    }
};