class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.length();
        if(n==1) return 0;
        int maxZeroes=0,maxOnes=0;
        if(s[0]=='0') maxZeroes++;
        else maxOnes++;
        vector<int> result;
        for(int i=1;i<n;i++)
        {
            if(s[i]!=s[i-1])
            {
                if(s[i-1]=='0') result.push_back(maxZeroes);
                else result.push_back(maxOnes);
            }
            if(s[i]=='0')
            {
                maxZeroes++;
                maxOnes=0;
            }
            else
            {
                maxOnes++;
                maxZeroes=0;
            }
        }
        if(maxOnes>0) result.push_back(maxOnes);
        else if(maxZeroes>0) result.push_back(maxZeroes);
        if(result.size()<=1) return 0;
        int count=0;
        n=result.size();
        for(int i=0;i<n-1;i++)
        {
            count+=min(result[i],result[i+1]);
        }
        return count;
    }
};