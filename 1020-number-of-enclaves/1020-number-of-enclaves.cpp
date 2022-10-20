class Solution {
public:
    // same as surrounding regions
    
    void dfs(vector<vector<int>>&board , int i , int j , int n , int m)
    {
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=1)
            
            // dont change the condition from board[i][j]!='O' to board[i][j]=='X' ... it will work in some cases but in other cases it will fail..because if a cell has already be # then we call for that cell then the base condition should be executed and when it will  check that board[i][j]==X this will become false and base condition will never execute but if we put boars[i][j]!='O' then # will check whether it is not equal to O and this becomes true and base condition will execute otherwise the base condition will never execute and the recursion goes on. 
            return;
        
        board[i][j]='#';
        
        dfs(board,i+1,j,n,m);
        dfs(board,i,j-1,n,m);
        dfs(board,i,j+1,n,m);
        dfs(board,i-1,j,n,m);
        
        return;
            
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
     
        for(int i=0 ;i<n ;i++)
        {
            if(grid[i][0]==1)
                dfs(grid,i,0,n,m);
            if(grid[i][m-1]==1)
                dfs(grid,i,m-1,n,m);
        }
        
        for(int j=0; j<m;j++)
        {
            if(grid[0][j]==1)
                dfs(grid,0,j,n,m);
            if(grid[n-1][j]==1)
                dfs(grid,n-1,j,n,m);
                
        }
        
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0; j<m ;j++)
            {
                if(grid[i][j]==1)
                   count++;
                
            }
        }
        
        return count;
    }
};