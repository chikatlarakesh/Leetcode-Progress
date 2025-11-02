class Solution {
public:
    void markAll(int row,int col,int n,int m,vector<vector<int>>& result) {
        // go right
        for(int j=col+1;j<m;j++) {
            if(result[row][j] == -1 || result[row][j] == -2) break;
            result[row][j] = 1;
        }

        //go left
        for(int j=col-1;j>=0;j--) {
            if(result[row][j] == -1 || result[row][j] == -2) break;
            result[row][j] = 1;
        }

        // go up
        for(int i=row-1;i>=0;i--) {
            if(result[i][col] == -1 || result[i][col] == -2) break;
            result[i][col] = 1;
        }

        // go down
        for(int i=row+1;i<n;i++) {
            if(result[i][col] == -1 || result[i][col] == -2) break;
            result[i][col] = 1;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> result(m,vector<int>(n,0));
        for(int i=0;i<guards.size();i++) {
            int r = guards[i][0];
            int c = guards[i][1];
            result[r][c] = -1;
        }

        for(int i=0;i<walls.size();i++) {
            int r = walls[i][0];
            int c = walls[i][1];
            result[r][c] = -2;
        }

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(result[i][j] == -1) {
                    markAll(i,j,m,n,result);
                }
            }
        }

        int unoccupiedCells = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(result[i][j] == 0) {
                    unoccupiedCells++;
                }
            }
        }
        return unoccupiedCells;
    }
};