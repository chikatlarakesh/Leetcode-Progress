class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n=digits.size();
        int i,j,k;
        unordered_set<int> s;
        for(int i=0;i<n;i++)
        {
            if(digits[i]==0) continue;
            for(int j=0;j<n;j++)
            {
                if(j==i) continue;
                for(int k=0;k<n;k++)
                {
                    if(digits[k]%2!=0 || k==i || k==j) continue;
                    int val=digits[i]*100+digits[j]*10+digits[k];
                    s.insert(val);
                }        
            }
        }
        vector<int> result(s.begin(),s.end());
        sort(result.begin(),result.end());
        return result;
    }
};