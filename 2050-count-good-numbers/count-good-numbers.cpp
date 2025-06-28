class Solution {
public:
    long long MOD=1000000007;
    long long calculatePower(long long x,long long y)
    {
        if(y==0) return 1;
        long long half=calculatePower(x,y/2);
        long long ans=(half*half)%MOD;
        if(y%2==1) ans=(ans*x)%MOD;
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=n/2;
        return (calculatePower(5,even)*calculatePower(4,odd))%MOD;
    }
};