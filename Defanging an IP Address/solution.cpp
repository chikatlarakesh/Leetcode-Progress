string defangIPaddr(string address) {
        string r="";
        int n=address.length();
        for(int i=0;i<n;i++)
        {
            if(address.at(i)=='.')
            {
                string c="[.]";
                r=r+c;
            }
            else
            {
                r=r+address.at(i);
            }
        }
        return r;
    }
