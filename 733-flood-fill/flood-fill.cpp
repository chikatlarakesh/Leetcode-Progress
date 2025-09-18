class Solution {
public:
    void dfs(int row,int col,int initialColour,int color,vector<vector<int>>& visited,vector<pair<int,int>>& dir) {
        visited[row][col] = color;

        for(auto [r,c]: dir) {
            int i = row + r;
            int j = col + c;

            if(i>=0 && i<visited.size() && j>=0 && j<visited[0].size() && visited[i][j] == initialColour) {
                dfs(i,j,initialColour,color,visited,dir);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int initialColour = image[sr][sc]; 
        if(initialColour == color) return image;
        vector<vector<int>> visited = image;
        vector<pair<int,int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};

        dfs(sr,sc,initialColour,color,visited,dir);
        return visited;
    }

    // BFS
    // vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    //     int n = image.size();
    //     int m = image[0].size();
    //     int initialColour = image[sr][sc]; 
    //     if(initialColour == color) return image;
    //     vector<vector<int>> visited = image;
    //     vector<pair<int,int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
    //     queue<pair<int,int>> q;
    //     q.push({sr,sc});
    //     visited[sr][sc] = color;

    //     while(!q.empty()) {
    //         int row = q.front().first;
    //         int col = q.front().second;
    //         q.pop();

    //         for(auto [r,c]: dir) {
    //             int i = row + r;
    //             int j = col + c;

    //             if(i>=0 && i<n && j>=0 && j<m && visited[i][j] == initialColour) {
    //                 visited[i][j] = color;
    //                 q.push({i,j});
    //             }
    //         }
    //     }
    //     return visited;
    // }
};