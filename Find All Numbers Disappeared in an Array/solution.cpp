vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> set;
        int i;
        int n=nums.size();
        for(i=0;i<n;i++)
        {
            set.insert(nums[i]);
        }
        vector <int> vec;
        for(i=1;i<=n;i++)
        {
            if(set.find(i)==set.end())
            {
                vec.push_back(i);
            }
        }
        return vec;
    }
