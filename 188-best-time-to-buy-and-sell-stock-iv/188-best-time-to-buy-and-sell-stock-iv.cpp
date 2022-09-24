class Solution {
public:
    
    int dfs(vector<int>&prices , int i ,int n, int cap, int buy , vector<vector<vector<int>>>&dp)
    {
        if(cap==0)
            return  0;
        if(i>=n)
            return 0;
        if(dp[i][buy][cap]!=-1)
            return dp[i][buy][cap];
        if(buy==1)
        {
            return dp[i][buy][cap]= max(-prices[i]+dfs(prices,i+1,n,cap,0,dp),dfs(prices,i+1,n,cap,1,dp));
        }
        
        else
        {
            return dp[i][buy][cap]=max(prices[i]+dfs(prices,i+1,n,cap-1,1,dp),dfs(prices,i+1,n,cap,0,dp));
        }
    }
    
    int maxProfit(int k, vector<int>& prices) {
       
      int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
      return dfs(prices,0,n,k,1,dp);
        
    }
};