class Solution {
public:
   
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n=nums.size();
        int sum=0;
        vector<int>dp(n,0);
       
        for(int i=2 ; i<n ;i++)
        {
            int d= nums[i-1] - nums[i-2];
            if(nums[i]-nums[i-1]==d)
                dp[i]= 1+dp[i-1];
        }
       
        for(int i=0 ; i<n ;i++)
            sum = sum + dp[i];
        return sum;
    }
};