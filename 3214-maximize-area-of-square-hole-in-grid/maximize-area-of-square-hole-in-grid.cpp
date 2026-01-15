class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int hSize = hBars.size();
        int vSize = vBars.size();

        int maxHSize = 1, currHSize = 1;
        for(int i=1;i<hSize;i++) {
            if(hBars[i] - hBars[i-1] == 1) currHSize++;
            else currHSize = 1;
            maxHSize = max(maxHSize, currHSize);
        }

        int maxVSize = 1, currVSize = 1;
        for(int i=1;i<vSize;i++) {
            if(vBars[i] - vBars[i-1] == 1) currVSize++;
            else currVSize = 1;
            maxVSize = max(maxVSize, currVSize);
        }

        int minDist = min(maxHSize, maxVSize) + 1;
        return minDist * minDist;
    }
};