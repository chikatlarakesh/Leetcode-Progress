class FindSumPairs {
public:
    vector<int> nums1,nums2;
    unordered_map<int,int> mp;
    FindSumPairs(vector<int>& arr1, vector<int>& arr2) {
        nums1=arr1;
        nums2=arr2;
        for(int num:nums2) mp[num]++;
    }
    void add(int index, int val) {
        mp[nums2[index]]--;
        nums2[index]+=val;
        mp[nums2[index]]++;
    }
    
    int count(int tot) {
        int count=0;
        for(int num:nums1)
        {
            int complement=tot-num;
            count+=mp[complement];
        }
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */