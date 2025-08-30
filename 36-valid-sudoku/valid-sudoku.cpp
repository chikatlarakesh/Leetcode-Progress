class Solution {
public:
    bool checkValid(int row,int col,vector<vector<char>>& board,char target)
    {
        int startR=(row/3)*3;
        int startC=(col/3)*3;
        for(int i=0;i<9;i++)
        {
            if(i!=col && target==board[row][i]) return false;

            if(i!=row && target==board[i][col]) return false;

            if((startR+i/3!=row || startC+i%3!=col) &&
                (board[startR+i/3][startC+i%3]==target)) return false;
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    if(!checkValid(i,j,board,board[i][j])) return false;
                }
            }
        }
        return true;
    }
};