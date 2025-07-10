class Solution {
public:
    bool checkValid(int i,int j,vector<string>& board)
    {
        int row=i-1,col=j;

        while(row>=0)
        {
            if(board[row][col]=='Q') return false;
            row--;
        }

        row=i-1,col=j-1;
        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }

        row=i-1,col=j+1;
        while(row>=0 && col<board.size())
        {
            if(board[row][col]=='Q') return false;
            row--;
            col++;
        }

        return true;
    }

    void solveNQueens(int row,vector<string>& board,vector<vector<string>>& result)
    {
        int n=board.size();
        if(row==n)
        {
            result.push_back(board);
            return;
        }

        for(int col=0;col<n;col++)
        {
            board[row][col]='Q';
            if(checkValid(row,col,board)) solveNQueens(row+1,board,result);
            board[row][col]='.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n,string(n,'.'));
        solveNQueens(0,board,result);
        return result;
    }
};