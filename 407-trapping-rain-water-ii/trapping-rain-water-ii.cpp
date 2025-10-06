class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        using Node = pair<int,pair<int,int>>;
        priority_queue<Node,vector<Node>,greater<Node>> pq;

        for(int col=0;col<m;col++) {
            for(int row: {0,n-1}) {
                pq.push({heightMap[row][col],{row,col}});
                visited[row][col] = 1;
            }
        }

        for(int row=1;row<n-1;row++) {
            for(int col: {0,m-1}) {
                pq.push({heightMap[row][col],{row,col}});
                visited[row][col] = 1;
            }
        }

        int totalVolume = 0;
        vector<pair<int,int>> dir = {{0, 1},{1, 0},{0, -1},{-1, 0}};
        while(!pq.empty()) {
            int height = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            for(auto &[r,c]: dir) {
                int i = row + r;
                int j = col + c;

                if(i>=0 && i<n && j>=0 && j<m && !visited[i][j]) {
                    if(heightMap[i][j] < height) {
                        totalVolume += height - heightMap[i][j];
                        pq.push({height,{i,j}});
                    }
                    else {
                        pq.push({heightMap[i][j],{i,j}});
                    }
                    visited[i][j] = 1;
                }
            }
        }
        return totalVolume;
    }
};