class Solution {
public:
    bool wordSearch(int row,int col,int n,vector<vector<char>>& board, const string& word,int currIndex)
    {
        if(currIndex==n) return true;
        if(row==-1 || row==board.size() || col==-1 || col==board[0].size()) return false;
        else if(board[row][col]==' ' || word[currIndex]!=board[row][col]) return false;
        
        char temp=board[row][col];
        board[row][col]=' ';
        bool found = wordSearch(row-1,col,n,board,word,currIndex+1) || 
                     wordSearch(row+1,col,n,board,word,currIndex+1) ||
                     wordSearch(row,col-1,n,board,word,currIndex+1) ||
                     wordSearch(row,col+1,n,board,word,currIndex+1);

        board[row][col]=temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rowSize=board.size();
        int colSize=board[0].size();
        int n=word.length();

        for(int i=0;i<rowSize;i++)
        {
            for(int j=0;j<colSize;j++)
            {
                if(word[0]==board[i][j])
                {
                    if(wordSearch(i,j,n,board,word,0)) return true;
                }
            }
        }
        return false;
    }
};