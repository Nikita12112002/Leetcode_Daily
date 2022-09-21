class Solution {
public:
    
    int dfs(vector<int>&nums1 , vector<int>&nums2 , int i ,int j , vector<vector<int>>&dp, int &count)
    {
        if(i<0||j<0) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int take=0;
    if(nums1[i]==nums2[j])
    {
        take=1+dfs(nums1,nums2,i-1,j-1,dp,count);
    }
    int a=dfs(nums1,nums2,i-1,j,dp,count);
    int b=dfs(nums1,nums2,i,j-1,dp,count);
    count=max(count,take);
    
    return dp[i][j]=take;
        
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
       
        int n = nums1.size();
        int m = nums2.size();
        int count=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
         dfs(nums1,nums2,n-1,m-1,dp,count);
        return count;
    }
};