class Solution {
public:
    string reverseWords(string s) {
        // Reverse the entire string
        // 1. Find the first character that is not equal to space
        // 2. Move all the characters to the front filling up the spaces
        // 3. Reverse the substring and add a space
        // 4. Repeat the process

        int n=s.length();
        reverse(s.begin(),s.end());
        int i=0,j=0,start=0,end=0;
        while(j<n)
        {
            while(j<n && s[j]==' ') j++;
            start=i;
            while(j<n && s[j]!=' ')
            {
                s[i]=s[j];
                i++;
                j++;
            }
            end=i;
            reverse(s.begin()+start,s.begin()+end);
            if(j<n)
            {
                s[i]=' ';
                i++;
            }
        }
        if(i>0 && s[i-1]==' ') i--;
        return s.substr(0,i);

        // while(s.back()==' ') s.pop_back();
        // reverse(s.begin(),s.end());
        // while(s.back()==' ') s.pop_back();
        // reverse(s.begin(),s.end());

        // int n=s.length();
        // string ans="";
        // int i=n-1;
        // while(i>=0)
        // {
        //     string temp="";
        //     while(i>=0 && s[i]!=' ')
        //     {
        //         temp+=s[i];
        //         i--;
        //     }
        //     while(i>=0 && s[i]==' ') i--;
        //     reverse(temp.begin(),temp.end());
        //     ans+=temp;
        //     if(i!=-1) ans+=' ';
        // }
        // return ans;
        
    }
};