class Solution {
public:
    void markReachableFromOcean(int x,int y,vector<vector<int>>& visited,vector<vector<int>>& heights) {
        if(visited[x][y]) return;

        visited[x][y] = 1;
        queue<pair<int,int>> q;
        q.push({x,y});
        vector<pair<int,int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(auto &[r,c]: dir) {
                int i = row + r;
                int j = col + c;

                if(i>=0 && i<heights.size() && j>=0 && j<heights[0].size() && !visited[i][j] && heights[i][j] >= heights[row][col]) {
                    visited[i][j] = 1;
                    q.push({i,j});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));

        for(int i=0;i<n;i++) {
            markReachableFromOcean(i,0,pacific,heights);
            markReachableFromOcean(i,m-1,atlantic,heights);
        }

        for(int j=0;j<m;j++) {
            markReachableFromOcean(0,j,pacific,heights);
            markReachableFromOcean(n-1,j,atlantic,heights);
        }

        vector<vector<int>> result;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};