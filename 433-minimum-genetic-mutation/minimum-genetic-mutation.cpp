class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n = startGene.length();
        unordered_set<string> visited(bank.begin(),bank.end());
        queue<pair<int,string>> q;
        q.push({0,startGene});
        visited.erase(startGene);

        vector<char> choices = {'A','C','G','T'};
        while(!q.empty()) {
            int mutations = q.front().first;
            string gene = q.front().second;
            q.pop();
            if(gene == endGene) return mutations;

            for(int i=0;i<n;i++) {
                char originalChar = gene[i];
                for(char ch: choices) {
                    gene[i] = ch;
                    if(visited.count(gene)) {
                        visited.erase(gene);
                        q.push({mutations+1,gene});
                    }
                }
                gene[i] = originalChar;
            }
        }
        return -1;
    }
};