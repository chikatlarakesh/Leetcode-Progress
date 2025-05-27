class Solution {
public:
    void generateAllPrimes(vector<int>& nums,int n)
    {
        for(int i=2;i*i<=n;i++)
        {
            if(nums[i]==1)
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    nums[j]=0;
                }
            }
        }
    }

    vector<vector<int>> findPrimePairs(int n) {
        vector<int> primeNumbers(n+1,1);
        generateAllPrimes(primeNumbers,n);
        vector<vector<int>> primePairs;
        for(int i=2;i<=n/2;i++)
        {
            int complement=n-i;
            if(primeNumbers[i]==1 && primeNumbers[complement]==1)
            {
                primePairs.push_back({i,complement});
            }
        }
        return primePairs;
    }
};