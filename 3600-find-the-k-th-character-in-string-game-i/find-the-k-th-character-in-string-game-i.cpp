class Solution {
public:
    char kthCharacter(int k) {
        string ans="a";
        while(ans.length()<k)
        {
            int n=ans.length();
            for(int i=0;i<n;i++)
            {
                char ch=ans[i]+1;
                ans+=ch;
            }
        }
        return ans[k-1];
    }
};