class Solution {
public:
/*should find: how many numbers missing at each index = arr[r]-(r+1)
            how many more should i find = k-(arr[r]-(r+1))
             result=arr[r]+remaining missing nums
                                 |
             result=arr[r]+k-(arr[r]-(r+1))
                    arr[r]+k-(arr[r]-r-1)
                    arr[r]+k-arr[r]+r+1 (Cancel pos and neg arr[r])
             result=k+r+1
             result=k+1+r (l=r+1 kabatti)
             so, result=l+k
            h+1+k la kuda raskochu
*/
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int l=0;
        int r=n-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            int missing=arr[m]-(m+1);
            if(missing<k)
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        return l+k;
    }
};