class Solution {
public:
    string getPermutation(int n, int k) {
        string s="";
        for(char ch='1';ch<=n+'0';ch++) s+=ch;
        string ans="";
        do{
            if(k==1)
            {
                ans=s;
                break;
            }
            k--;
        }while(next_permutation(s.begin(),s.end()));

        return ans;
    }
};