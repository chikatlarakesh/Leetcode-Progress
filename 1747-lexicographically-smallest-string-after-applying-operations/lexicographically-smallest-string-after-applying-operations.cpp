class Solution {
public:
    // string findLexSmallestString(string s, int a, int b) {
    //     int n = s.length();
    //     unordered_set<string> visited;
    //     queue<string> q;
    //     string ans = s;
    //     q.push(s);
    //     visited.insert(s);

    //     while(!q.empty()) {
    //         string temp = q.front();
    //         q.pop();
    //         if(temp < ans) ans = temp;

    //         // add
    //         string addedString = temp;
    //         for(int i=1;i<n;i+=2) {
    //             int val = (addedString[i] - '0') + a;
    //             val = val % 10;
    //             addedString[i] = val + '0';
    //         }
    //         if(visited.find(addedString) == visited.end()) {
    //             visited.insert(addedString);
    //             q.push(addedString);
    //         }

    //         // rotate
    //         string rotatedString = temp;
    //         for(int i=0;i<n;i++) {
    //             int ind = (i + b) % n;
    //             rotatedString[ind] = temp[i];
    //         }
    //         if(visited.find(rotatedString) == visited.end()) {
    //             visited.insert(rotatedString);
    //             q.push(rotatedString);
    //         }
    //     }
    //     return ans;
    // }

    string ans;
    void dfs(int n,string& s,int a,int b, unordered_set<string>& visited) {
        if(visited.count(s)) return;
        visited.insert(s);
        if(s < ans) ans = s;

        // add
        string addedString = s;
        for(int i=1;i<n;i+=2) {
            int val = (addedString[i] - '0') + a;
            val = val % 10;
            addedString[i] = val + '0';
        }
        if(!visited.count(addedString)) {
            dfs(n,addedString,a,b,visited);
        }

        // rotate
        string rotatedString = s;
        for(int i=0;i<n;i++) {
            int ind = (i + b) % n;
            rotatedString[ind] = s[i];
        }
        if(!visited.count(rotatedString)) {
            dfs(n,rotatedString,a,b,visited);
        }      
    }

    string findLexSmallestString(string s, int a, int b) {
        int n = s.length();
        unordered_set<string> visited;
        ans = s;

        dfs(n,s,a,b,visited);
        return ans;
    }
};