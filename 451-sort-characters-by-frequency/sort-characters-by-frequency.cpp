class Solution {
public:
    class comparer{
        public:
        bool operator()(pair<char,int>& a,pair<char,int>& b)
        {
            return a.second>b.second;
        }
    };

    string frequencySort(string s) {
        int n=s.length();
        vector<pair<char,int>> frequency(123);
        for(char ch:s)
        {
            int freq=frequency[ch].second;
            frequency[ch]={ch,freq+1};
        }
        sort(frequency.begin(),frequency.end(),comparer());
        string ans="";
        for(int i=0;i<123;i++)
        {
            if(frequency[i].second==0) break;
            char ch=frequency[i].first;
            int freq=frequency[i].second;
            ans+=string(freq,ch);
        }
        return ans;
    }
};