class Solution {
public:
    const int MOD=1000000007;
    int fact(int n)
    {
        long long val=1;
        for(int i=n;i>=1;i--)
        {
            val=(val*i)%MOD;
        }
        return val;
    }

    int countPermutations(vector<int>& complexity) {
        int n=complexity.size();
        for(int i=1;i<n;i++)
        {
            if(complexity[0]>=complexity[i]) return 0;
        }
        return fact(n-1);
    }
};