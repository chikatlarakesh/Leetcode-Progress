class Solution {
public:
    bool isPossible(vector<int>& piles, int h, int k){
        int i,temp=0;
        int n=piles.size();
        for(i=0;i<n;i++)
        {
            temp=piles[i]/k;
            if(piles[i]%k!=0)
            {
                temp++;
            }
            h=h-temp;
            if(h<0)
            {
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h){
        bool result;
        int l=1;
        int r=1000000000;
        while(l<=r)
        {
            int k=l+(r-l)/2;
            result=isPossible(piles,h,k);
            if(result==true)
            {
                r=k-1;
            }
            else
            {
                l=k+1;
            }
        }
        return l;
    }
};