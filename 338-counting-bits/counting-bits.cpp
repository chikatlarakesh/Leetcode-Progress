class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        for(int j=0;j<=n;j++)
        {
            int count=0;
            int i=j;
            while(i)
            {
                i=(i&i-1);
                count++;
            }
            result.push_back(count);
        }
        return result;
    }
};