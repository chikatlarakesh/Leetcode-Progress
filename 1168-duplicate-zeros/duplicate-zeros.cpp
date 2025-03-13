class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();
        int count=0;
        for(int num: arr)
        {
            if(num==0)
            {
                count++;
            }
        }
        int i;
        int j=n+count-1;
        for(i=n-1;i>=0;i--)
        {
            if(j<n)
            {
                arr[j]=arr[i];
            }
            j--;
            if(arr[i]==0)
            {
                if(j<n)
                {
                    arr[j]=0;
                }
                j--;
            }
        }
    }
};