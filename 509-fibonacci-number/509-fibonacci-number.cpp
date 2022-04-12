class Solution {
public:
    int fib(int n) {
       //This is the recursive code
        
        // if(n==0)
        //     return 0;
        // if(n==1)
        //     return 1;
        // return fib(n-1)+fib(n-2);
        
        // Now converting into dp code-Tabulation method;
        
//         vector<int>dp(n+1);
//          if(n==0)
//              return 0;
//         if(n==1)
//             return 1;
        
//         dp[0]=0;
//         dp[1]=1;
        
//         for(int i=2 ;i<n+1;i++)
//         {
//             dp[i]=dp[i-1]+dp[i-2];
//         }
        
//         return dp[n];
        
        //SPACE OPTIMIZATION METHOD
        
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        
        int prev2=0 , prev1=1,curr;
        
        for(int i=2;i<n+1;i++)
        {
            curr = prev1+prev2;
            
            prev2=prev1;
            prev1=curr;
        }
        
        return curr;
        
	
}
    
};