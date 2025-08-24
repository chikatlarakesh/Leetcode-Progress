class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char ch: s) mp[ch]++;
        priority_queue<pair<int,char>> pq;
        for(auto &it: mp)
        {
            pq.push({it.second,it.first});
        }

        string ans="";
        while(!pq.empty())
        {
            int freq=pq.top().first;
            char ch=pq.top().second;
            pq.pop();
            while(freq--) ans+=ch;
        }
        return ans;
    }
};

// class Solution {
// public:
//     string frequencySort(string s) {
//         int n=s.length();
//         pair<int,char> freq(26,0);
//         for(int i=0;i<26;i++)
//         {
//             freq[i]={0,i+'a'};
//         }

//         for(char ch:s)
//         {
//             freq[ch-'a'].first++;
//         }
//         sort(freq.begin(),freq.end());

//         string ans="";
//         for(auto &it: freq)
//         {
//             int freq=it.first;
//             char ch=it.second;
//             if(freq==0) break;
//             while(freq--) ans+=ch;
//         }
//         return ans;
//     }
// };