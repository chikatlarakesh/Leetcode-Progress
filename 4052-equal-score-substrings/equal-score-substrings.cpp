class Solution {
public:
    bool scoreBalance(string s) {
        int n = s.length();
        vector<int> prefix(n);

        int prefixSum = 0;
        for(int i=0;i<n;i++) {
            prefixSum += (s[i] - 'a') + 1;
            prefix[i] = prefixSum;
        }

        int suffixSum = 0;
        for(int i=n-1;i>0;i--) {
            suffixSum += (s[i] - 'a') + 1;
            if(suffixSum == prefix[i-1]) return true;
        }
        return false;
    }
};