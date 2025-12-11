class Solution {
public:
    const int MOD = 1e9 + 7;
    long long fact(int n) {
        if(n == 1) return n;
        return ((n * fact(n-1)) % MOD);
    }

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int start = complexity[0];
        for(int i=1;i<n;i++) {
            if(complexity[i] <= start) return 0;
        }
        return (fact(n-1) % MOD);
    }
};