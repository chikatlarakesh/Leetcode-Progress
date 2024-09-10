int mostWordsFound(vector<string>& sentences) {
        int max=0;
        int i,j;
        for(i=0;i<sentences.size();i++)
        {
            int temp=1;
            string p=sentences[i];
            for(j=0;j<p.length();j++)
            {
                if(p[j]==' ')
                {
                    temp++;
                }
            }
            if(max<temp)
            {
                max=temp;
            }
        }
        return max;
    }
