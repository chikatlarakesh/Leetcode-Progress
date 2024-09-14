bool isValid(vector<vector<int>>& matrix, int x,int y)
    {
        bool value = true;
        int r=matrix.size();
        int c=matrix[0].size();
        int temp;
        temp=matrix[x][y];
        while(x<r&&y<c)
        {
            if(matrix[x][y]!=temp)
            {
                value=false;
                return value;
            }
            x++;
            y++;
        }
        return value;
    }
    bool isToeplitzMatrix(vector<vector<int>>& matrix) 
    {
        int i,temp;
        int r=matrix.size();
        int c=matrix[0].size();
        bool result=true;
        for(i=1;i<r;i++)
        {
            temp=isValid(matrix,i,0);
            if(temp==false)
            {
                result=false;
                return result;
            }
        }
        for(i=0;i<c;i++)
        {
            temp=isValid(matrix,0,i);
            if(temp==false)
            {
                result=false;
                return result;
            }
        }
    return result;
    }
