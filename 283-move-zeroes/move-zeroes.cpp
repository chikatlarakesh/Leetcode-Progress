class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n=arr.size();
        int count=0,j=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0) count++;
            else
            {
                arr[j]=arr[i];
                j++;
            }
        }
        j=n-1;
        while(count--)
        {
            arr[j]=0;
            j--;
        }
    }
};