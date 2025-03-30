class Solution {
public:
    int reverseDegree(string s) {
        int result=0;
        int n=s.length();
        int i;
        for(i=0;i<n;i++)
        {
            int val=('z'-s[i]+1)*(i+1);
            result+=val;
        }
        return result;
    }
};