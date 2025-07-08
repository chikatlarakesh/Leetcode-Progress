class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        sort(events.begin(),events.end());

        int day = events[0][0];
        int i = 0,maxEvents = 0;
        while(!pq.empty() || i < n)
        {
            while(i<n && events[i][0]<=day)
            {
                pq.push(events[i][1]);
                i++;
            }
            if(!pq.empty())
            {
                pq.pop();
                maxEvents++;
            }
            day++;

            while(!pq.empty() && day>pq.top())
            {
                pq.pop();
            }
        }
        return maxEvents;
    }
};