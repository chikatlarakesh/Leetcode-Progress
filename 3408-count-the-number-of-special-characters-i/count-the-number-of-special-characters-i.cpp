class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count=0;
        vector<int> result(52,0);
        for(char ch:word)
        {
            if(isupper(ch))
            {
                int ind=ch-65;
                result[ind]=result[ind]+1;
            }
            else
            {
                int ind=ch-71;
                result[ind]=result[ind]+1;
            }
        }
        for(int i=0;i<26;i++)
        {
            if(result[i]>0 && result[i+26]>0) count++;
        }
        return count;
    }
};