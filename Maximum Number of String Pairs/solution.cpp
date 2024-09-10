int maximumNumberOfStringPairs(vector<string>& words) {
        int n=words.size();
        int i,j;
        int count=0;
        string a,rev;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                a=words[i];
                rev=words[j];
                reverse(rev.begin(),rev.end());
                if(a==rev)
                {
                    count++;
                }
            }
        }
        return count;
    }
