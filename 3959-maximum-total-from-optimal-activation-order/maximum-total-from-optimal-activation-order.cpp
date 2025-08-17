class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        int n=limit.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++) mp[limit[i]].push_back(value[i]);

        long long maxValue=0;
        for(auto& it: mp)
        {
            int L=it.first;
            auto& arr=it.second;
            sort(arr.rbegin(),arr.rend());
            int size=min(L,(int)arr.size());
            for(int i=0;i<size;i++) maxValue+=arr[i];
        }
        return maxValue;
    }
};