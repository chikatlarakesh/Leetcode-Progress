class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            if(intervals.empty()) return {newInterval};
            vector<vector<int>> insertIntervals;
            int n=intervals.size();
            int i=0;
            //left segment add cheyataniki
            while(i<n && intervals[i][1]<newInterval[0])
            {
                insertIntervals.push_back(intervals[i]);
                i++;
            }

            //overlapping segment add cheyataniki
            while(i<n && intervals[i][0]<=newInterval[1])
            {
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);
                i++;
            }
            insertIntervals.push_back(newInterval);

            //right segment add cheyataniki
            while(i<n)
            {
                insertIntervals.push_back(intervals[i]);
                i++;
            }
            return insertIntervals;

        // if(intervals.empty()) return {newInterval};
        // intervals.push_back(newInterval);
        // sort(intervals.begin(),intervals.end());
        // vector<vector<int>> insertIntervals;
        // insertIntervals.push_back({intervals[0][0],intervals[0][1]});
        // int n=intervals.size();
        // for(int i=1;i<n;i++)
        // {
        //     int start=intervals[i][0];
        //     int end=intervals[i][1];
        //     if(start<=insertIntervals.back()[1])
        //     {
        //         insertIntervals.back()[1]=max(insertIntervals.back()[1],end);
        //     }
        //     else 
        //     {
        //         insertIntervals.push_back({start,end});
        //     }
        // }
        // return insertIntervals;
    }
};