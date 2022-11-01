class Solution {
public:
    
    int dfs(vector<vector<int>>&grid , int k  , int i , int j,  vector<vector<vector<int>>> &dp, vector<vector<bool>> &visited)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visited[i][j])
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
        
       
        visited[i][j]=true;
        int up = dfs(grid,k,i-1,j,dp,visited);
          int left = dfs(grid,k,i,j-1,dp,visited);
        int down = dfs(grid,k,i+1,j,dp,visited);
      
        int right = dfs(grid,k,i,j+1,dp,visited);
        
       visited[i][j]=false;
        
       int ans1= min(up,down);
        int ans2= min(left,right);
        
           return dp[i][j][k] =1+ min(up, min(down, min(left, right)));
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1, -1)));
         vector<vector<bool>> visited(n, vector<bool>(m, false));
        int res = dfs(grid,k,n-1,m-1,dp,visited);
        

        
        if(res >= m*n)
            return -1;
        return res;
    }
            

};
