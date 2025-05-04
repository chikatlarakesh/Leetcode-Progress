class Solution {
public:
    int maxProduct(int n) {
        vector<int> result;
        while(n>0)
        {
            result.push_back(n%10);
            n=n/10;
        }
        sort(result.begin(),result.end());
        n=result.size();
        return result[n-1]*result[n-2];
    }
};