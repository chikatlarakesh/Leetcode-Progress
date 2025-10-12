class ExamTracker {
public:
    using ll = long long;
    vector<ll> times, prefixScore;
    ll prefixSum = 0;
    ExamTracker() {
        
    }
    
    void record(int time, int score) {
        prefixSum += score;
        times.push_back(time);
        prefixScore.push_back(prefixSum);
    }
    
    long long totalScore(int startTime, int endTime) {
        ll score = 0;
        if(times.empty()) return 0;

        int start = lower_bound(times.begin(),times.end(),startTime) - times.begin();
        int end = upper_bound(times.begin(),times.end(),endTime) - times.begin() - 1;

        if(start > times.size() || end < 0 || start > end) return 0;
        if(start == 0) return prefixScore[end];
        return prefixScore[end] - prefixScore[start-1];
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */