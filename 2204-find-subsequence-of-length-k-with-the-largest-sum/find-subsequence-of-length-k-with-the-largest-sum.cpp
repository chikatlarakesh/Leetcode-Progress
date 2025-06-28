class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(pq.size()==k && nums[i]>pq.top().first) pq.pop();
            if(pq.size()<k) pq.push({nums[i],i});
        }
        vector<pair<int,int>> result;
        while(!pq.empty())
        {
            result.push_back({pq.top().second,pq.top().first});
            pq.pop();
        }
        sort(result.begin(),result.end());
        vector<int> ans;
        for(int i=0;i<result.size();i++)
        {
            ans.push_back(result[i].second);
        }
        return ans;
    }
};