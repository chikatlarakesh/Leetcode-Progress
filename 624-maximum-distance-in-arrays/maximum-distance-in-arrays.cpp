class Solution {
public:
    int firstMinimum(vector<vector<int>>& arrays)
    {
        int n=arrays.size();
        int minElement=INT_MAX,maxElement=INT_MIN,ind=0;
        for(int i=0;i<n;i++)
        {
            int m=arrays[i].size();
            if(arrays[i][0]<=minElement)
            {
                minElement=arrays[i][0];
                ind=i;
            }
        }

        for(int i=0;i<n;i++)
        {
            int m=arrays[i].size();
            if(i==ind) continue;
            maxElement=max(maxElement,arrays[i][m-1]);
        }
        return abs(maxElement-minElement);
    }

    int maxDistance(vector<vector<int>>& arrays) {
        int minDist=firstMinimum(arrays);
        int n=arrays.size();
        int minElement=INT_MAX,maxElement=INT_MIN,ind=0;
        for(int i=0;i<n;i++)
        {
            int m=arrays[i].size();
            if(arrays[i][m-1]>=maxElement)
            {
                maxElement=arrays[i][m-1];
                ind=i;
            }
        }

        for(int i=0;i<n;i++)
        {
            int m=arrays[i].size();
            if(i==ind) continue;
            minElement=min(minElement,arrays[i][0]);
        }
        int maxDist=abs(maxElement-minElement);
        return max(minDist,maxDist);
    }
};