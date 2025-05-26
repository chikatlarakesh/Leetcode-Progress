class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty()) return {newInterval};
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> insertIntervals;
        insertIntervals.push_back({intervals[0][0],intervals[0][1]});
        int n=intervals.size();
        int prevEnd=intervals[0][1];
        for(int i=1;i<n;i++)
        {
            int start=intervals[i][0];
            int end=intervals[i][1];
            if(start<=prevEnd)
            {
                insertIntervals.back()[1]=max(insertIntervals.back()[1],end);
                prevEnd=insertIntervals.back()[1];
            }
            else 
            {
                insertIntervals.push_back({start,end});
                prevEnd=end;
            }
        }
        return insertIntervals;
    }
};