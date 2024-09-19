string decodeMessage(string key, string message) {
        map<char,char> mp;
        int i;
        int temp=97;
        for(i=0;i<key.length();i++)
        {
            char c=key.at(i);
            if(c!=' ' && mp.find(c)==mp.end())
            {
                mp.insert({c,(char)temp});
                temp++;
            }
        }
        string p="";
        for(i=0;i<message.length();i++)
        {
            char ch=message.at(i);
            if(ch==' ')
            {
                p=p+' ';
            }
            else
            {
                p=p+mp[ch];
            }
        }
        return p;
    }
