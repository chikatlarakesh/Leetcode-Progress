class Solution {
public:
    bool checkValid(int row,int col,vector<vector<char>>& board,char target)
    {
        int startR=(row/3)*3;
        int startC=(col/3)*3;
        for(int i=0;i<9;i++)
        {
            if(target==board[row][i]) return false;

            if(target==board[i][col]) return false;

            if(board[startR+i/3][startC+i%3]==target) return false;
        }
        return true;
    }

    bool backtrack(vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char ch='1';ch<='9';ch++)
                    {
                        if(checkValid(i,j,board,ch))
                        {
                            board[i][j]=ch;
                            if(backtrack(board)) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};