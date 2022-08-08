class Solution {
public:
    int dfs(vector<int>&piles , int i , int j , int flag , vector<vector<vector<int>>>&dp)
    {
        if(j-i+1==1)
            return piles[i];
        if(dp[i][j][flag]!=-1)
            return dp[i][j][flag];
        
        int alice=0;
        int bob=0; 
        
        if(flag==0)
            alice = max(piles[i]+dfs(piles,i+1,j,1,dp) , piles[j]+dfs(piles,i,j-1,1,dp));
        if(flag==1)
             bob = max(piles[i]+dfs(piles,i+1,j,1,dp) , piles[j]+dfs(piles,i,j-1,1,dp));
        
        return dp[i][j][flag]= max(alice,bob);
    }
    bool stoneGame(vector<int>& piles) {
        int n =piles.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return dfs(piles,0,n-1,0,dp);
    }
};