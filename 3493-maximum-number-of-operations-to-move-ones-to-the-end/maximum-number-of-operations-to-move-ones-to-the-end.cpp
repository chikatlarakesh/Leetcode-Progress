class Solution {
public:
    int getCount(int ind, string &s) {
        int count = 0;
        for(int i=ind;i>=0;i--) {
            if(s[i] == '1') count++;
            else break;
        }
        return count;
    }

    int maxOperations(string s) {
        int n = s.length();
        int prevCount = 0, ops = 0;
        for(int i=0;i<n-1;i++) {
            if(s[i] == '1' && s[i+1] == '0') {
                int count = getCount(i,s) + prevCount;
                ops += count;
                prevCount = count;
            }
        }
        return ops;
    }
};