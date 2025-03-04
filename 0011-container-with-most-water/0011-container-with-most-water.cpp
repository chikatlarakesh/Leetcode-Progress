class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1,result=0;
        int small=INT_MAX;
        while(i<j)
        {
            small=min(height[i],height[j]);
            result=max(result,(j-i)*small);
            if(height[i]<height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return result;
    }
};