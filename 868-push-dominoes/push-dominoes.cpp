class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        int force=0;
        string ans="";
        //vector<int> leftForce(n);
        vector<int> rightForce(n);
        for(int i=0;i<n;i++)
        {
            if(dominoes[i]=='R') force=n;
            else if(dominoes[i]=='L') force=0;
            else 
            {
                if(force!=0) force--;
            }
            rightForce[i]=force;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(dominoes[i]=='L') force=n;
            else if(dominoes[i]=='R') force=0;
            else 
            {
                if(force!=0) force--;
            }
            rightForce[i]=rightForce[i]-force;
        }
        for(int i=0;i<n;i++)
        {
            if(rightForce[i]>0) ans+='R';
            else if(rightForce[i]<0) ans+='L';
            else ans+='.';
        }
        return ans;
    }
};