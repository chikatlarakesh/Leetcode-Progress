int singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        int n=nums.size();
        int i;
        for(i=0;i<n;i++)
        {
            map[nums[i]]++;
        }
        for(auto it=map.begin();it!=map.end();it++)
        {
            if(it -> second==1)
            {
                return it -> first;
            }
        }
        return -1;
    }
