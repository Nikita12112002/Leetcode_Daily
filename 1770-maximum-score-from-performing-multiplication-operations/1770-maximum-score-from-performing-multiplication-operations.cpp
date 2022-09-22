class Solution {
public:
     int dfs(vector<int>&nums , vector<int>&multipliers , int n , int m , int i , int j , int k , vector<vector<int>>&dp)
        {
         
         // right pointer can be said as ->suppose right is 1 so we can say last from starting so right is dependent on start we can express it in terms of start.
            if(k==m)
                return 0;
            
           if(dp[k][i]!=INT_MIN)
               return dp[k][i];
            int left = nums[i]*multipliers[k]+dfs(nums,multipliers,n,m,i+1,j,k+1,dp);
            int right=nums[j]*multipliers[k]+dfs(nums,multipliers,n,m,i,j-1,k+1,dp);
            
            return dp[k][i]=max(left,right);
        }
    
    
   
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
         
        
        int n=nums.size();
        int m = multipliers.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,INT_MIN));
        return dfs(nums,multipliers,n,m,0,n-1,0,dp);
 

        
      
    }
};