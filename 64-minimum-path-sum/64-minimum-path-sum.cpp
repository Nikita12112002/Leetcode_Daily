class Solution {
public:
    int dfs(vector<vector<int>>&nums , int i , int j , vector<vector<int>>&dp)
    {
        if(i==0 && j==0)
            return nums[i][j];
        if(i<0 || j<0)
            return 1e9;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j]=min(nums[i][j]+dfs(nums,i-1,j,dp) , nums[i][j]+dfs(nums,i,j-1,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return dfs(grid,n-1,m-1,dp);
    }
};