class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int,vector<int>,greater<int>> pq;
        sort(events.begin(),events.end());
        int count=0;
        int start=events[0][0];
        int end=0;
        for(int i=0;i<events.size();i++)
        {
            end=max(end,events[i][1]);
        }
        int j=0;
        for(int i=start;i<=end;i++)
        {
            while(j<events.size())
            {
                if(i==events[j][0])
                {
                    pq.push(events[j][1]);
                    j++;
                }
                else
                {
                    break;
                }
            }
            while(!pq.empty()&&pq.top()<i)
            {
                pq.pop();
            }
            if(!pq.empty())
            {
                pq.pop();
                count+=1;
            }
        }
        return count;
    }
};