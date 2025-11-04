class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        using Node = pair<int,int>;
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int> result;
        int l = 0;

        for(int r=0;r<n;r++) {
            mp[nums[r]]++;
            if(r - l + 1 == k) {
                priority_queue<Node,vector<Node>,greater<Node>> pq;
                for(auto &it: mp) {
                    int freq = it.second;
                    int val = it.first;
                    if(!pq.empty()) {
                        int topFreq = pq.top().first;
                        int topVal = pq.top().second;
                        if(pq.size() == x) {
                            if(freq > topFreq) pq.pop();
                            else if(freq == topFreq && val > topVal) pq.pop();
                        }
                    }
                    if(pq.size() < x) pq.push({freq,val});
                }
                int sum = 0;
                while(!pq.empty()) {
                    int freq = pq.top().first;
                    int val = pq.top().second;
                    pq.pop();
                    sum += (val * freq);
                }
                result.push_back(sum);

                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
        }
        return result;
    }
};