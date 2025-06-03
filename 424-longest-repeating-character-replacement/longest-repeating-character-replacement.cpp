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
            if(r-l+1-maxFreq>k)
            {
                int ind=s[l]-'A';
                hash[ind]--;
                l++;
            }
            if(r-l+1-maxFreq<=k) maxLen=max(maxLen,r-l+1);
        }
        return maxLen;
    }
};