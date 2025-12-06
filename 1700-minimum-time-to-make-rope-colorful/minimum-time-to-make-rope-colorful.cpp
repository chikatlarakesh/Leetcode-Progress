class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int remTime = 0;
        int totalTime = accumulate(neededTime.begin(),neededTime.end(),0);
        int n = colors.size();
        for(int i=0;i<n;i++) {
            if(i < n-1 && colors[i] == colors[i+1]) {
                    neededTime[i+1] = max(neededTime[i],neededTime[i+1]);
            }
            else remTime += neededTime[i];
        }
        return totalTime - remTime;
    }
};