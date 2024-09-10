int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> map;
        int i;
        int count=0;
        for(int num: nums)
        {
            if(map.find(num)!=map.end())
            {
                count=count+map[num];
            }
            map[num]++;
        }
        return count;
    }
