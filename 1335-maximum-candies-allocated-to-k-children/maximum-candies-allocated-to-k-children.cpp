class Solution {
public:
    bool ispossible(vector<int>& candies, long long k,int m)
    {
        int n=candies.size();
        int i,temp;
        for(i=0;i<n;i++)
        {
            temp=candies[i]/m;
            k=k-temp;
            if(k<=0)
            {
                return true;
            }
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        int l=1;
        int r=10000000;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(ispossible(candies,k,m)==true)
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        return r;
    }
};