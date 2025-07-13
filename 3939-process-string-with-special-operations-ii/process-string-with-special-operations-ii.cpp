class Solution {
public:
    char processStr(string s, long long k) {
        int n=s.length();
        vector<unsigned long long> vec(n);
        for(int i=0;i<n;i++)
            {
                unsigned long long len;
                if(i>0)
                {
                    len=vec[i-1];
                }
                else len=0;

                if(s[i]>='a' && s[i]<='z') vec[i]=len+1;
                else if(s[i]=='*')
                {
                    if(len>0) vec[i]=len-1;
                    else vec[i]=0;
                }
                else if(s[i]=='#') vec[i]=len*2;
                else vec[i]=len;
            }

        if(n==0 || k<0 || (unsigned long long)k>=vec.back()) return '.';

        unsigned long long currIndx=(unsigned long long)k;
        for(int i=n-1;i>=0;i--)
            {
                unsigned long long len;
                if(i>0) len=vec[i-1];
                else len=0;

                if(s[i]>='a' && s[i]<='z')
                {
                    if(currIndx==len) return s[i];
                }
                else if(s[i]=='#')
                {
                    if(currIndx>=len) currIndx-=len;
                }
                else if(s[i]=='%') currIndx=len-1-currIndx;
            }
        return '.';
    }
};