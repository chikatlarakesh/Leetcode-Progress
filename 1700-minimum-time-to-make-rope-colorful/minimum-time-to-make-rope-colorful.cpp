class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int minTime = 0;
        int prev = neededTime[0];
        for(int i=1;i<n;i++) {
            int curr = neededTime[i];
            if(colors[i] != colors[i-1]) {
                prev = 0;
            }
            minTime += min(prev,curr);
            prev = max(prev,curr);
        }
        return minTime;


        // vector<pair<char,int>> arr;
        // arr.push_back({colors[0],neededTime[0]});
        // int minTime = 0;
        // for(int i=1;i<n;i++) {
        //     char ch = arr.back().first;
        //     int time = arr.back().second;
        //     if(colors[i] == ch) {
        //         if(time < neededTime[i]) {
        //             minTime += time;
        //             arr.back().second = neededTime[i];
        //         }
        //         else minTime += neededTime[i];
        //     }
        //     else arr.push_back({colors[i],neededTime[i]});
        // }
        // return minTime;
    }
};