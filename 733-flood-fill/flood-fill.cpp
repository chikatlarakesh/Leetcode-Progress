class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int initialColour = image[sr][sc]; 
        if(initialColour == color) return image;
        vector<vector<int>> visited = image;
        vector<pair<int,int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
        queue<pair<int,int>> q;
        q.push({sr,sc});
        visited[sr][sc] = color;

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(auto [r,c]: dir) {
                int i = row + r;
                int j = col + c;

                if(i>=0 && i<n && j>=0 && j<m && visited[i][j] == initialColour) {
                    visited[i][j] = color;
                    q.push({i,j});
                }
            }
        }
        return visited;
    }
};