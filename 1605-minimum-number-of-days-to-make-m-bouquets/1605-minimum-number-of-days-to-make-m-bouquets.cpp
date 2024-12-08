class Solution {
public:
    bool isPossible(vector<int>& nums, int day, int m, int k){
        int n=nums.size();
        int i,took=0;
        for(i=0;i<n;i++)
        {
            if(nums[i]<=day)
            {
                took++;
            }
            else
            {
                took=0;
            }
            if(took==k)
            {
                m--;
                took=0;
            }
            if(m==0)
            {
                return true;
            }
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=1;
        int r=1000000000;
        int exd=r;
        bool temp;
        while(l<=r)
        {
            int j=l+(r-l)/2;
            temp=isPossible(bloomDay,j,m,k);
            if(temp==true)
            {
                r=j-1;
            }
            else
            {
                l=j+1;
            }
        }
        if(l==exd+1)
        {
            return -1;
        }
        return l;
    }
};