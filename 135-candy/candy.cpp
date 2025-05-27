class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> left(n,1);
        vector<int> right(n,1);
        int count=1;
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                count++;
                left[i]=count;
            }
            else count=1;
        }
        count=1;
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                count++;
                right[i]=count;
            }
            else count=1;
        }
        int minCandies=0;
        for(int i=0;i<n;i++)
        {
            minCandies+=max(left[i],right[i]);
        }
        return minCandies;
    }
};