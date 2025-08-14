class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.length();
        string ans="";
        for(int i=0;i<n-2;i++)
        {
            if(num[i]==num[i+1] && num[i+1]==num[i+2])
            {
                string temp=string(3,num[i]);
                ans=max(ans,temp);
            } 
        }
        return ans;
    }
};