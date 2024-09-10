int finalValueAfterOperations(vector<string>& operations) {
        int count=0;
        int n=operations.size();
        for(int i=0;i<n;i++)
        {
            if((operations.at(i)=="X++")||(operations.at(i)=="++X"))
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return count;
    }
