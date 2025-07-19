class Solution {
public:
    vector<bool> sieve(long long n)
    {
        vector<bool> primes(n,true);
        if(n>0) primes[0]=false;
        if(n>1) primes[1]=false;
        for(long long p=2;p*p<n;p++)
            {
                if(!primes[p]) continue;
                for(long long i=p*p;i<n;i+=p)
                    {
                        primes[i]=false;
                    }
            }
        return primes;
    }
    
    long long splitArray(vector<int>& nums) {
        long long n=nums.size();
        vector<bool> primes=sieve(n);
        long long primeSum=0;
        for(int i=0;i<n;i++)
            {
                if(primes[i]) primeSum+=nums[i];
            }
        long long totalSum=accumulate(nums.begin(),nums.end(),0LL);
        long long nonPrimeSum=totalSum-primeSum;
        long long ans=llabs(primeSum-nonPrimeSum);
        return ans;
    }
};