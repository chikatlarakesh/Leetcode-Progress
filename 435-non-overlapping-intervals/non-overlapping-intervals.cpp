class Solution {
private:
    class comparer{
        public:
        bool operator()(vector<int>& a,vector<int>& b)
        {
            return a[1]<b[1];
        }
    };

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),comparer());
        int removeIntervals=0;
        int prevEndInterval=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int start=intervals[i][0];
            int end=intervals[i][1];
            if(start<prevEndInterval)
            {
                removeIntervals++;
            }
            else prevEndInterval=end;
        }
        return removeIntervals;
    }
};