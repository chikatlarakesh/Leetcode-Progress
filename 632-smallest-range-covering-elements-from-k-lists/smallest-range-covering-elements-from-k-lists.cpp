class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<k;i++)
        {
            int val=nums[i][0];
            mini=min(mini,val);
            maxi=max(maxi,val);
            pq.push({val,i,0});
        }

        int start=mini,end=maxi;
        while(!pq.empty())
        {
            auto top=pq.top();
            pq.pop();
            int val=get<0>(top);
            int row=get<1>(top);
            int col=get<2>(top);
            mini=val;

            if(maxi-mini<end-start)
            {
                start=mini;
                end=maxi;
            }
            int n=nums[row].size();
            if(col+1<n)
            {
                int val=nums[row][col+1];
                maxi=max(maxi,val);
                pq.push({val,row,col+1});
            }
            else break;
        }
        return {start,end};
    }
};