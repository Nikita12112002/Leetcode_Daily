class Solution {
public:
    int dfs(vector<int>&nums , int i, int prev , int d , vector<vector<int>>&dp , int n)
    {
        if(i==n)
            return 0;
        if(nums[i]-nums[prev]!=d)
            return 0;
        if(dp[i][prev]!=-1)
            return dp[i][prev];
        return dp[i][prev]= 1+dfs(nums,i+1,i,d,dp,n);
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n=nums.size();
        int count=0;
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        for(int i=0 ; i<n-2 ;i++)
        {
            int d= nums[i+1] - nums[i];
            count=count+dfs(nums,i+2,i+1,d,dp,n);
        }
        return count;
    }
};