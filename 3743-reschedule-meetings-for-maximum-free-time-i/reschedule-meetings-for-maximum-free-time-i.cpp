class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeTime;
        freeTime.push_back(startTime[0]);
        int maxFreeTime=0,l=0,sum=0;
        int n=startTime.size();
        for(int i=1;i<n;i++)
        {
            freeTime.push_back(startTime[i]-endTime[i-1]);
        }
        freeTime.push_back(eventTime-endTime[n-1]);
        k++;
        for(int r=0;r<freeTime.size();r++)
        {
            sum+=freeTime[r];
            if(r-l+1>k)
            {
                sum-=freeTime[l];
                l++;
            }
            maxFreeTime=max(sum,maxFreeTime); 
        }

        return maxFreeTime;
    }
};