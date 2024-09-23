bool isIsomorphic(string s, string t) {
        map<char,char> m1; 
        map<char,char> m2;              
        bool result= true;
        int i;
        for(i=0;i<s.length();i++)
        {
            char p=s.at(i);             
            char r=t.at(i);            
            if(m1.find(p)==m1.end()&&m2.find(r)==m2.end())
            {
                m1.insert({p,r});
                m2.insert({r,p});
            }
            else if((m1.find(p)!=m1.end()&&m1[p]!=r)||(m2.find(r)!=m2.end()&&m2[r]!=p))
            {
                result=false;
                break;
            }
        }
        return result;
    }
