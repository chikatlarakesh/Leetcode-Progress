class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n=dimensions.size();
        int maxArea=0,longestDiagonal=0;
        for(int i=0;i<n;i++)
        {
            int length=dimensions[i][0];
            int width=dimensions[i][1];
            int diagonal=((length*length)+(width*width));
            if(diagonal>=longestDiagonal)
            {
                int area=length*width;
                if(diagonal==longestDiagonal) maxArea=max(maxArea,area);
                else maxArea=area;
                longestDiagonal=diagonal;
            }
        }
        return maxArea;
    }
};