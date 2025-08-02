class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        int n=landStartTime.size();
        int m=waterStartTime.size();

        int minTime=INT_MAX;
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                    {
                        int lEndTime=landStartTime[i]+landDuration[i];
                        int nextWStart=max(lEndTime,waterStartTime[j]);
                        int time1=nextWStart+waterDuration[j];

                        int wEndTime=waterStartTime[j]+waterDuration[j];
                        int nextLStart=max(wEndTime,landStartTime[i]);
                        int time2=nextLStart+landDuration[i];

                        minTime=min({minTime,time1,time2});
                    }
            }
        return minTime;
    }
};