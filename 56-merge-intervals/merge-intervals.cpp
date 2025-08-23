class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> result;
        result.push_back({intervals[0][0],intervals[0][1]});
        int n=intervals.size();
        int i=1,j=0;
        while(i<n)
        {
            int start=intervals[i][0];
            int end=intervals[i][1];
            if(result[j][1]>=start && end>=result[j][1]) 
            {
                result[j][1]=end;
            }
            else if(start>result[j][1])
            {
                result.push_back({start,end});
                j++;
            }
            i++;
        }
        return result;
    }
};