class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int maxLen=0,l=0,maxFreq=0;
        vector<int> hash(26,0);
        for(int r=0;r<n;r++)
        {
            int ind=s[r]-'A';
            hash[ind]++;
            maxFreq=max(maxFreq,hash[ind]);
            while(r-l+1-maxFreq>k)
            {
                int ind=s[l]-'A';
                hash[ind]--;
                maxFreq=0;
                for(int i=0;i<26;i++)
                {
                    maxFreq=max(maxFreq,hash[i]);
                }
                l++;
            }
            maxLen=max(maxLen,r-l+1);
        }
        return maxLen;
    }
};