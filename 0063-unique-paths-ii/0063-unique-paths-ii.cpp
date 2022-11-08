class Solution {
public:
    int dfs(vector<vector<int>>&grid , int i , int j,vector<vector<int>>&dp)
    {
        if(i<0 || j<0  || i>=grid.size() || j>=grid[0].size() || grid[i][j]==1)
        {
            return 0;
        }
        
        if(i==0 && j==0)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        
        int left = dfs(grid,i,j-1,dp);
        int up =   dfs(grid,i-1,j,dp);
        
        return dp[i][j]=left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        
        return dfs(grid,n-1,m-1,dp);
    }
};