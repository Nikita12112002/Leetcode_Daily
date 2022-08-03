class Solution {
public:
    int dfs(string &s , string &t , int i , int j , vector<vector<int>>&dp)
    {
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==t[j])
            return dp[i][j] = 1+dfs(s,t,i-1,j-1,dp);
        return dp[i][j]=max(dfs(s,t,i-1,j,dp),dfs(s,t,i,j-1,dp));
    }
    int minInsertions(string s) {
        
        int n = s.length();
        int m =n;
        string t = s;
        reverse(t.begin(),t.end());
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        for(int i=0 ; i<=n ;i++)
        {
            dp[i][0]=0;
        }
        for(int j=0 ; j<=m ;j++)
            dp[0][j]=0;
        
        for(int i=1 ; i<=n ;i++)
        {
            for(int j=1 ; j<=m ;j++)
            {
                  if(s[i-1]==t[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
                
        return n-dp[n][m];
        
    }
};