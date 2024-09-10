int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int low=colors[0];
        int result=0;
        int result1=n-1;
        int i,answer;
        int difference=0;
        int diff=0;
        if(n==2)
        {
            return 1;
        }
        for(i=0;i<n-1;i++)
        {
            if(colors[i]!=colors[n-1])
            {
                diff=result1-i;
                break;
            }
        }
        for(i=n-1;i>=0;i--)
        {
            if(colors[i]!=low)
            {
                difference=i-result;
                break;
            }
        }
        if(difference>diff)
        {
            return difference;
        }
        else
        {
            return diff;
        }
    }
