class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        for(int i=0;i<n;i++)
        {
            pq.push({arr[i],i});
        }
        int rank=0,prevElement=INT_MIN;
        while(!pq.empty())
        {
            int index=pq.top().second;
            int currElement=pq.top().first;
            if(currElement==prevElement)
            {
                arr[index]=rank;
            }
            else
            {
                rank++;
                arr[index]=rank;
                prevElement=currElement;
            }
            pq.pop();
        }
        return arr;


        // unordered_map<int,int> m;
        // vector<int> result;
        // result.insert(result.end(),arr.begin(),arr.end());
        // sort(result.begin(),result.end());
        // int i,count=0;
        // int n=arr.size();
        // for(i=0;i<n;i++)
        // {
        //     if(m.find(result[i])==m.end())
        //     {
        //         count++;
        //         m[result[i]]=count;
        //     }
        // }
        // for(i=0;i<n;i++)
        // {
        //     arr[i]=m[arr[i]];
        // }
        // return arr;
    }
};