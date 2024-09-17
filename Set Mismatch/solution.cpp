vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> s;
        int i;
        int duplicate=-1;
        int missing =-1;
        for (int num : nums) 
        {
            if (s.find(num) != s.end()) 
            {
                duplicate = num;
            } 
            else 
            {
                s.insert(num);
            }
        }
        for(i=1;i<=nums.size();i++)
        {
            if(s.find(i)==s.end())
            {
                missing=i;
                break;
            }
        }
        return {duplicate,missing};
    }
