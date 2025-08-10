class Solution {
public:
    int getSortedFormat(int n)
    {
        int ans=0;
        while(n)
        {
            ans+=pow(10,n%10);
            n/=10;
        }
        return ans;

    }

    bool reorderedPowerOf2(int n) {
        int input=getSortedFormat(n);

        for(int i=0;i<=29;i++)
        {
            int output=getSortedFormat(1<<i);
            if(input==output) return true;
        }
        return false;
    }
};