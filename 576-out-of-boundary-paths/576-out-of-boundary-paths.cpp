class Solution {
public:
    
    long long dp[101][101][101];
    int mod = 1000000007;
    
    int dfs(int r, int c, int mx, int i, int j)
    {
        if(mx < 0) 
            return 0;
        
        if(i < 0 || j < 0 || i >= r || j >= c) 
            return 1;
        
        if(dp[i][j][mx] != -1) 
            return dp[i][j][mx];
        
        long long left = dfs(r, c, mx - 1, i , j - 1) % mod;
        long long right = dfs(r, c, mx - 1, i, j + 1) % mod;
        long long top = dfs(r, c, mx - 1, i - 1, j) % mod;
        long long btm = dfs(r, c, mx - 1, i + 1, j) % mod;
        
        dp[i][j][mx] = (left+ right + top + btm ) % mod;
        
        return dp[i][j][mx];
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) 
    {
            memset(dp, -1, sizeof(dp));
            return   dfs(m, n, maxMove, startRow, startColumn);
        
    }
};