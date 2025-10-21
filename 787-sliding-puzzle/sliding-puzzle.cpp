class Solution {
public:
    using Node = pair<int,pair<pair<int,int>,vector<vector<int>>>>;

    int slidingPuzzle(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        string solvedBoard = "123450";
        unordered_map<int,vector<int>> mp = {{0,{1,3}}, {1,{0,2,4}}, {2,{1,5}}, 
                                {3,{0,4}}, {4,{1,3,5}}, {5,{2,4}}};
        unordered_set<string> visited;
        string start = "";
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                start += to_string(board[i][j]);
            }
        }

        queue<pair<int,string>> q;
        q.push({0,start});
        visited.insert(start);

        while(!q.empty()) {
            int moves = q.front().first;
            string currBoard = q.front().second;
            q.pop();
            if(currBoard == solvedBoard) return moves;

            int indexOfZero = currBoard.find('0');
            for(int swapInd : mp[indexOfZero]) {
                swap(currBoard[swapInd],currBoard[indexOfZero]);
                if(!visited.count(currBoard)) {
                    visited.insert(currBoard);
                    q.push({moves+1,currBoard});
                }
                swap(currBoard[swapInd],currBoard[indexOfZero]);
            }
        }
        return -1;
    }


    // int slidingPuzzle(vector<vector<int>>& board) {
    //     int n = board.size();
    //     int m = board[0].size();
    //     vector<vector<int>> solvedBoard = {{1,2,3},{4,5,0}};
    //     set<vector<vector<int>>> visited;

    //     // find zero coordinates
    //     int row = 0,col = 0;
    //     for(int i=0;i<n;i++) {
    //         for(int j=0;j<m;j++) {
    //             if(board[i][j] == 0) {
    //                 row = i;
    //                 col = j;
    //                 break;
    //             }
    //         }
    //     }

    //     queue<Node> q;
    //     q.push({0,{{row,col},board}});
    //     visited.insert(board);

    //     vector<pair<int,int>> dir = {{-1, 0},{0, 1},{1, 0},{0, -1}};
    //     while(!q.empty()) {
    //         auto it = q.front();
    //         int moves = it.first;
    //         int row = it.second.first.first;
    //         int col = it.second.first.second;
    //         vector<vector<int>> currBoard = it.second.second;
    //         if(currBoard == solvedBoard) return moves;
    //         q.pop();

    //         for(auto &[r,c]: dir) {
    //             int i = row + r;
    //             int j = col + c;
                
    //             if(i>=0 && i<n && j>=0 && j<m) {
    //                 swap(currBoard[row][col],currBoard[i][j]);
    //                 if(!visited.count(currBoard)) {
    //                     visited.insert(currBoard);
    //                     q.push({moves+1,{{i,j},currBoard}});
    //                 }
    //                 swap(currBoard[row][col],currBoard[i][j]);
    //             }
    //         }
    //     }
    //     return -1;
    // }
};