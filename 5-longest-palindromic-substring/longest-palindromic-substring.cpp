class Solution {
public:
    bool checkPalindrome(int i,int j,string& s)
    {
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n=s.length();

        int maxLen=0,startingPoint=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(checkPalindrome(i,j,s)==true)
                {
                    if(j-i+1>maxLen)
                    {
                        maxLen=j-i+1;
                        startingPoint=i;
                    }
                }
            }
        }
        return s.substr(startingPoint,maxLen);
    }
};