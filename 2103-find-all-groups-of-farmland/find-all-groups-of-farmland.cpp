class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& visited,vector<vector<int>>& result,vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        visited[row][col] = 1;

        queue<pair<int,int>> q;
        q.push({row,col});

        vector<pair<int,int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int maxRow = row, maxCol = col;
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            maxRow = max(maxRow,r);
            maxCol = max(maxCol,c);
            q.pop();

            for(auto &[x,y]: dir) {
                int i = r + x;
                int j = c + y;

                if(i>=0 && i<n && j>=0 && j<m && !visited[i][j] && land[i][j] == 1) {
                    visited[i][j] = 1;
                    q.push({i,j});
                }
            }
        }
        result.push_back({row,col,maxRow,maxCol});
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> result;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!visited[i][j] && land[i][j] == 1) {
                    bfs(i,j,visited,result,land);
                }
            }
        }
        return result;
    }
};