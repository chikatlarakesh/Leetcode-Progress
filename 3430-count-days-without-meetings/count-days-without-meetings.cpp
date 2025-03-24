class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
         int start=meetings[0][0],end=meetings[0][1];
         int count=end-start+1;
         for(int i=1;i<meetings.size();i++){
              if(meetings[i][0]<=end) start=end+1;
              else start=meetings[i][0];
              if(meetings[i][1]>end) end=meetings[i][1];
              count+=(end-start+1);
         }  
         return days-count;
    }
};