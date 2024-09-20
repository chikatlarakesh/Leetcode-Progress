vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector <int> v;
        unordered_map<int,int> map;
        int i;
        int n=nums.size();
        for(i=0;i<n;i++)
        {
            if(map.find(nums[i])==map.end())
            {
                map[nums[i]]=i;
            }
            if(map.find(target-nums[i])!=map.end() && i!=map[target-nums[i]])
            {
                v.push_back(i);
                v.push_back(map[target-nums[i]]);
                break;
            }
        }
        return v;
    }
