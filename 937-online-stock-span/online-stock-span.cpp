class StockSpanner {
public:
    vector<int> result;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count=1;
        int n=result.size();
        int i=n-1;
        while(!result.empty() && i>=0)
        {
            if(result[i]<=price) count++;
            else break;
            i--;
        }
        result.push_back(price);
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */