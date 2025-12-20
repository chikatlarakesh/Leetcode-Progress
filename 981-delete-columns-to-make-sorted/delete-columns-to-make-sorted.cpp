class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        int count = 0;
        for(int i=0;i<m;i++) {
            char prev = 'a';
            for(int j=0;j<n;j++) {
                if(prev > strs[j][i]) {
                    count++;
                    break;
                }
                prev = strs[j][i];
            }
        }
        return count;
    }
};