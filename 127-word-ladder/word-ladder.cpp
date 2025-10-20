class Solution {
public:
    using Node = pair<int,string>;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.length();
        unordered_set<string> visited;
        for(string word: wordList) visited.insert(word);
        if(!visited.count(endWord)) return 0;

        // {steps,word};
        queue<Node> q;
        q.push({1,beginWord});
        visited.erase(beginWord);

        while(!q.empty()) {
            int steps = q.front().first;
            string word = q.front().second;
            q.pop();
            if(word == endWord) return steps;

            for(int i=0;i<n;i++) {
                char originalChar = word[i];
                for(char ch = 'a';ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(visited.count(word)) {
                        visited.erase(word);
                        q.push({steps+1,word});
                    }
                }
                word[i] = originalChar;
            }
        }
        return 0;
    }
};