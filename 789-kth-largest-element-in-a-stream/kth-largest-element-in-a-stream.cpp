class KthLargest {
public:
    int size=0;
    priority_queue<int,vector<int>,greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(int num:nums)
        {
            pq.push(num);
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) {
        if(pq.size()<size) pq.push(val);
        else if(val>pq.top())
        {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */