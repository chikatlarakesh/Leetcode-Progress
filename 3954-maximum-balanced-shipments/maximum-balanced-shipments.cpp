class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n=weight.size();
        int start=0,end=0;
        int maxi=0,count=0;
        while(start<n && end<n)
            {
                maxi=max(maxi,weight[end]);
                if(weight[end]!=maxi && weight[end]<maxi)
                {
                    count++;
                    start=end+1;
                    maxi=0;
                }
                end++;
            }
        return count;
    }
};