int lengthOfLastWord(string s) {
        int count=0;
        int i;
        int n=s.length();
        for(i=n-1;i>=0;i--)
        {
            if(s.at(i) != ' ')
            {
                count++;
            }
            else if(count>0)
            {
                break;
            }
        }
        return count;
    }
