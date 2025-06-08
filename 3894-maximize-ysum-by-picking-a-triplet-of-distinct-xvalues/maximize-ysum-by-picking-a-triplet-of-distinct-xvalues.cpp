class Solution {
public:
    class comparer{
        public:
        bool operator()(pair<int,int>& a,pair<int,int>& b)
        {
            return a.first>b.first;
        }
    };
    
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        vector<pair<int,int>> vec;
        int n=x.size();
        for(int i=0;i<n;i++) vec.push_back({y[i],x[i]});
        sort(vec.begin(),vec.end(),comparer());
        unordered_set<int> distinct;
        int maxSum=0;
        for(int i=0;i<n;i++)
            {
                if(distinct.size()<3)
                {
                    if(distinct.find(vec[i].second)==distinct.end())
                    {
                        distinct.insert(vec[i].second);
                        maxSum+=vec[i].first;
                    }
                }
                else break;
            }
        if(distinct.size()<3) return -1;
        return maxSum;
    }
};