class Solution {
public:
    int climbStairs(int n) {
        
        //Since we have count no of ways we can thought of recursion
        
//         if(n==0)
//             return 1;
//         if(n==1)
//          return 1;
        
//         return climbStairs(n-1)+climbStairs(n-2);
        
        //TABULATION METHOD -DP
//         vector<int>dp(n+1);
//         if(n==0)
//             return 1;
//         if(n==1)
//             return 1;
        
//         dp[0]=1;
//         dp[1]=1;
//         for(int i=2 ;i<n+1 ;i++)
//         {
//             dp[i]=dp[i-1]+dp[i-2];
//         }
        
//         return dp[n];
        
        //SPACE OPTIMIZATION
        
        int prev2=1 , prev1=1 ,curr;
        
        if(n<=1)
            return 1;
        
        for(int i=2 ;i<n+1 ;i++)
        {
            curr=prev2+prev1;
            prev2=prev1;
            prev1=curr;
        }
        
        return curr;
     }
};