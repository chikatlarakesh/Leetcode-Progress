vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        int large=-1;
        int i;
        for(i=n-1;i>=0;i--)
        {
            int temp=arr[i];
            arr[i]=large;
            if(temp>large)
            {
                large=temp;
            }
        }
        return arr;
    }
