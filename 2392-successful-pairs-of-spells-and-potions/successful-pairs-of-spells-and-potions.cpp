class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        using ll = long long;
        sort(potions.begin(),potions.end());
        int n = spells.size();
        int m = potions.size();
        vector<int> result(n);

        for(int i=0;i<n;i++) {

            int l = 0, r = m-1;
            while(l<=r) {
                int m = l + (r-l) / 2;
                ll currPotion = (long long) spells[i] * potions[m]; 
                if(currPotion >= success) {
                    r = m - 1;
                }
                else l = m + 1;
            }
            result[i] = m - l;
        }
        return result;
    }
};