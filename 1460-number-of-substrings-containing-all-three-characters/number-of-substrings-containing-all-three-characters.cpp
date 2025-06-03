class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        vector<int> result(3,-1);
        int substrings=0;
        for(int i=0;i<n;i++)
        {
            int ind=s[i]-'a';
            result[ind]=i;
            if(result[0]!=-1 && result[1]!=-1 && result[2]!=-1)
            {
                substrings+=1+min({result[0],result[1],result[2]});
            }
        }
        return substrings;
    }
};