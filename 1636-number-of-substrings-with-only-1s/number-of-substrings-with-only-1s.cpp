class Solution {
public:
    const int MOD = 1e9+7;
    int numSub(string s) {
        int n = s.length();
        int count = 0,result = 0;
        for(char ch: s) {
            if(ch == '1') count++;
            else count = 0;
            result = (result + count) % MOD;
        }
        return result;
    }
};