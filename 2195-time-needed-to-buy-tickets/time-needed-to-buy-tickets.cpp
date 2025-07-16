class Solution {
public:
    int timeRequiredToBuy(vector<int>& nums, int k) {
        int n=nums.size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++) q.push({nums[i],i});
        int totalTime=0;
        while(!q.empty())
        {
            totalTime++;
            int firstPerson=q.front().first;
            int index=q.front().second;
            firstPerson--;
            if(index==k && firstPerson==0) break;
            q.pop();
            if(firstPerson!=0) q.push({firstPerson,index});
        }
        return totalTime;
    }
};