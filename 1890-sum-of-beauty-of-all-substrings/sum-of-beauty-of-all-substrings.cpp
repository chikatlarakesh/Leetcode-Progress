class Solution {
public:
    int leastFrequent(vector<int>& freq)
    {
        int ans=INT_MAX;
        for(int i=0;i<26;i++)
        {
            if(freq[i]!=0) ans=min(ans,freq[i]);
        }
        return ans;
    }

    int mostFrequent(vector<int>& freq)
    {
        int ans=INT_MIN;
        for(int i=0;i<26;i++)
        {
            ans=max(ans,freq[i]);
        }
        return ans;
    }

    int beautySum(string s) {
        int n=s.length();
        int totalBeauty=0;
        for(int i=0;i<n;i++)
        {
            vector<int> freq(26,0);
            for(int j=i;j<n;j++)
            {
                freq[s[j]-'a']++;
                int beauty=mostFrequent(freq)-leastFrequent(freq);
                totalBeauty+=beauty;
            }
        }
        return totalBeauty;
    }
};