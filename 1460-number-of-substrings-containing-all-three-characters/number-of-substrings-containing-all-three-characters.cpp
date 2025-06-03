class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int a=-1,b=-1,c=-1,substrings=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a') a=i;
            else if(s[i]=='b') b=i;
            else c=i;
            if(a!=-1 && b!=-1 && c!=-1)
            {
                substrings+=1+min({a,b,c});
            }
        }
        return substrings;
        
        // //vector<int> result(3,-1);
        // int substrings=0;
        // for(int i=0;i<n;i++)
        // {
        //     //int ind=s[i]-'a';
        //     //result[ind]=i;
        //     // if(result[0]!=-1 && result[1]!=-1 && result[2]!=-1)
        //     // {
        //     //     substrings+=1+min({result[0],result[1],result[2]});
        //     // }
        // }
        // return substrings;
    }
};