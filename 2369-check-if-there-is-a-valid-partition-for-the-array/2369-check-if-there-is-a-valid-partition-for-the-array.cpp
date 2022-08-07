class Solution {
public:
    bool dfs(vector<int>&nums , int i , vector<int>&dp , int n)
    {
        if(i==n)
            return true;
       
        if(dp[i]!=-1)
            return dp[i];
        bool res=0;
        if(i+1<n && nums[i]==nums[i+1])
        {
              if(dfs(nums,i+2,dp,n) )return true;
              
            
                 if(i+2<n &&nums[i]==nums[i+2])
                  {
                     if(dfs(nums,i+3 , dp,n))return true;
                  }
              
            
        }
       
         if(i+2<n && nums[i+1]-nums[i]==1 && nums[i+2]-nums[i+1]==1)
        {
            if(dfs(nums,i+3,dp,n))return true;
        }
        
        return dp[i]=false;
    }
    bool validPartition(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==2)
        {
            if(nums[0]==nums[1])
                return true;
        }
        
        vector<int>dp(n,-1);
        return dfs(nums,0,dp,n);
    }
};