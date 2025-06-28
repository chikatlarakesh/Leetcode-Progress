class Solution {
public:
    long long MOD=1000000007;
    long long calculatePower(long long x,long long y)
    {
        if(y==0) return 1;
        long long ans=calculatePower(x,y/2);
        ans*=ans;
        ans%=MOD;
        if(y%2!=0) ans*=x;
        ans%=MOD;
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even=n/2;
        if(n%2!=0) even++;
        long long odd=n/2;
        return (calculatePower(5,even)*calculatePower(4,odd))%MOD;
    }
};