class Solution {
public:
    int captureForts(vector<int>& forts) {
        int i,count=0;
        int result=0;
        bool oneTaken=false;
        int n=forts.size();
        for(i=0;i<n;i++)
        {
            if(forts[i]==1)
            {
                count=0;
                oneTaken=true;
            }
            else if(forts[i]==-1)
            {
                result=max(result,count);
                oneTaken=false;
            }
            else if(forts[i]==0 && oneTaken==true) count++;
        }
        count=0,oneTaken=false;
        for(i=n-1;i>=0;i--)
        {
            if(forts[i]==1)
            {
                count=0;
                oneTaken=true;
            }
            else if(forts[i]==-1)
            {
                result=max(result,count);
                oneTaken=false;
            }
            else if(forts[i]==0 && oneTaken==true) count++;
        }
        return result;
    }
};