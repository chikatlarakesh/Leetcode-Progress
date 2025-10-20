class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<int,string>> q;
        unordered_set<string> visited(deadends.begin(),deadends.end());
        if(visited.count("0000")) return -1;

        q.push({0,"0000"});
        visited.insert("0000");
        while(!q.empty()) {
            int turns = q.front().first;
            string wheels = q.front().second;
            q.pop();
            if(wheels == target) return turns;

            for(int i=0;i<4;i++) {
                char originalChar = wheels[i];
                int val = wheels[i] - '0';
                for(int dir : {-1, 1}) {
                    int newVal = (val + dir + 10) % 10;
                    wheels[i] = newVal + '0';
                    if(!visited.count(wheels)) {
                        visited.insert(wheels);
                        q.push({turns+1,wheels});
                    }
                }
                wheels[i] = originalChar;
            }
        }
        return -1;
    }
};