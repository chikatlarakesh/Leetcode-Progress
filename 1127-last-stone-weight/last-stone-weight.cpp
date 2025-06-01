class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int num:stones) pq.push(num);
        while(pq.size()>1)
        {
            int largest=pq.top();
            pq.pop();
            int secLargest=pq.top();
            pq.pop();
            pq.push(largest-secLargest);
        }
        return pq.top();
    }
};