class Solution {
public:
    bool isPossible(int n, vector<int>& nums,int capacity){
        int m=nums.size();
        int i,temp;
        for(i=0;i<m;i++)
        {
            temp=nums[i]/capacity;
            if(nums[i]%capacity!=0)
            {
                temp++;
            }
            n=n-temp;
            if(n<0)
            {
                return false;
            }
        }
        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1;
        int r=100000;
        bool temp;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            temp=isPossible(n,quantities,m);
            if(temp==true)
            {
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return l;
    }
};