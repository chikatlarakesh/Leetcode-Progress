class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char,int> dChar;
        for(char ch: s)
        {
            dChar[ch]++;
        }
        if(dChar.size()<=k) return 0;
        vector<int> result;
        for(auto it=dChar.begin();it!=dChar.end();it++)
        {
            result.push_back(it->second);
        }
        sort(result.begin(),result.end(),greater<int>());
        int sum=0;
        int n=result.size();
        int i=n-1;
        while(result.size()>k)
        {
            sum+=result[i];
            result.pop_back();
            i--;
        }
        return sum;
    }
};