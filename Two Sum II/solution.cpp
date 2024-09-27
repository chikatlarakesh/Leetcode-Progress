vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int> result;
        int n=numbers.size();
        int low=0;
        int high=n-1;
        int sum;
        while(low<high)
        {
            sum=numbers[low]+numbers[high];
            if(sum==target)
            {
                result.push_back(low+1);
                result.push_back(high+1);
                break;
            }
            else if(sum<target)
            {
                low++;
            }
            else
            {
                high--;
            }
        }
        return result;
    }
