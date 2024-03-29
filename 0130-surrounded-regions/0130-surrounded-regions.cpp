class Solution {
public:
    
    void dfs(vector<vector<char>>&board , int i , int j , int n , int m)
    {
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!='O')
            
            // dont change the condition from board[i][j]!='O' to board[i][j]=='X' ... it will work in some cases but in other cases it will fail..because if a cell has already be # then we call for that cell then the base condition should be executed and when it will  check that board[i][j]==X this will become false and base condition will never execute but if we put boars[i][j]!='O' then # will check whether it is not equal to O and this becomes true and base condition will execute otherwise the base condition will never execute and the recursion goes on. 
            return;
        
        board[i][j]='#';
        
        dfs(board,i+1,j,n,m);
        dfs(board,i,j-1,n,m);
        dfs(board,i,j+1,n,m);
        dfs(board,i-1,j,n,m);
        
        return;
            
    }
    
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        
     
        for(int i=0 ;i<n ;i++)
        {
            if(board[i][0]=='O')
                dfs(board,i,0,n,m);
            if(board[i][m-1]=='O')
                dfs(board,i,m-1,n,m);
        }
        
        for(int j=0; j<m;j++)
        {
            if(board[0][j]=='O')
                dfs(board,0,j,n,m);
            if(board[n-1][j]=='O')
                dfs(board,n-1,j,n,m);
                
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0; j<m ;j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='#')
                    board[i][j]='O';
            }
        }
        
        return;
    }
};

