class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n=g.size();
        int m=s.size();
        int i=0,j=0,maxCount=0;
        while(i<n && j<m)
        {
            if(s[j]>=g[i])
            {
                i++;
                maxCount++;
            }
            j++;
        }
        return maxCount;
    }
};