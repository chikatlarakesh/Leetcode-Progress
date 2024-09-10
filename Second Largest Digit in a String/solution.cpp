int secondHighest(string s) {
    int max1=INT_MIN;
    int max2=INT_MIN;
        for(char c:s)
        {
            if(isdigit(c))
            {
                int a= c - '0';
                if(a>max1)
                {
                    max2=max1;
                    max1=a;
                }
                else if(a>max2&&a!=max1)
                {
                    max2=a;
                }
            }
        }
        if(max2==INT_MIN)
        {
            return -1;
        }
        return max2;
    }
