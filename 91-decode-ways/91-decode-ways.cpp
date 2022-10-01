class Solution {
public:
    
    int dfs(string s , int i , int n , vector<int>&dp)
    {
        if(s[i]=='0')
            return 0;
        
        if(i==n-1)
            return 1;
        
        if(i==n)
            return 1;
       
            if(dp[i]!=-1)
                return dp[i];
        int left=0 , right=0;
        
         if(i+1<n)
            left = dfs(s,i+1,n,dp);
        
        if((s[i]-'0')*10+(s[i+1]-'0')<=26)
           right = dfs(s,i+2,n,dp);
        
        return dp[i]=left+right;
    }
    int numDecodings(string s) {
        
        int n = s.length();
        vector<int>dp(n,-1);
        
        if(s[0]=='0')
            return 0;
        
    
         return dfs(s,0,n,dp);
    }
};