class Solution {
public:
    using Node = pair<int,string>;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.length();
        unordered_set<string> visited;
        for(string word: wordList) visited.insert(word);
        if(!visited.count(endWord)) return 0;

        // {steps,word};
        priority_queue<Node,vector<Node>,greater<Node>> pq;
        pq.push({1,beginWord});

        while(!pq.empty()) {
            int steps = pq.top().first;
            string word = pq.top().second;
            pq.pop();
            visited.erase(word);
            if(word == endWord) return steps;

            for(int i=0;i<n;i++) {
                string temp = word;
                for(char ch = 'a';ch <= 'z'; ch++) {
                    temp[i] = ch;
                    if(visited.count(temp)) {
                        pq.push({steps+1,temp});
                    }
                }
            }
        }
        return 0;
    }
};