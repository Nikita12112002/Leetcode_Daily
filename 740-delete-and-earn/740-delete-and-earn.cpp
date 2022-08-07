class Solution {
public:
    int dfs(vector<int>&nums , int i , vector<int>&dp)
    {
        if(i==0)
        {
            return nums[i];
        }
        
        if(i<0)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
       
        int notpick = dfs(nums,i-1,dp);
    
        int  pick = i*nums[i]+dfs(nums,i-2,dp);
        
        return dp[i]=max(pick,notpick);
    }
    int deleteAndEarn(vector<int>& nums) {
        
        
        int n = nums.size();
       
        
        int maxi = *max_element(nums.begin(),nums.end());
    
       vector<int>dp(maxi+1,-1),freq(maxi+1,0);
    
      
        for(int i=0 ; i<nums.size() ;i++)
        {
            freq[nums[i]]++;
        }
        
        int sz = freq.size();
        return dfs(freq,sz-1,dp);
    }
};
