class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j] == 0) {
                    visited[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }

        vector<pair<int,int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[row][col] = steps;

            for(auto &[r,c]: dir) {
                int i = row + r;
                int j = col + c;

                if(i>=0 && i<n && j>=0 && j<m && !visited[i][j]) {
                    visited[i][j] = 1;
                    q.push({{i,j},steps+1});
                }
            }
        }
        return dist;
    }
};