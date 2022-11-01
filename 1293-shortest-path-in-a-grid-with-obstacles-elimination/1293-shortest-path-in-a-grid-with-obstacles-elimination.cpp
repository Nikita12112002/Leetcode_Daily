class Solution {
public:
    
    int dfs(vector<vector<int>>&grid , int k  , int i , int j,  vector<vector<vector<int>>> &dp)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==2)
            return 1e9;
        
         if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        
        if(i==0 && j==0)
            return dp[i][j][k]=0;
        
         if(grid[i][j]==1)
        {
            if(k==0)
                return dp[i][j][k]=1e9;
            k--;
           
        }
        
        int c= grid[i][j];
        grid[i][j]=2;
       
        int top = dfs(grid, k, i-1, j,dp);
        int left = dfs(grid, k, i, j-1,dp);
        int down = dfs(grid, k, i+1, j,dp);
        int right = dfs(grid, k, i, j+1,dp);
       
        grid[i][j]=c;
        
        return dp[i][j][k] = 1+min(top, min(left, min(right, down)));
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1, -1)));
        
        int res = dfs(grid,k,n-1,m-1,dp);
        

        
        if(res >= 1e9)
            return -1;
        return res;
    }
            

};
