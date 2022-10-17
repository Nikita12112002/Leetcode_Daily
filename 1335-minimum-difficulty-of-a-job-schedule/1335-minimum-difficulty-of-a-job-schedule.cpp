class Solution {
public:
    
    int solve( int idx, int d, vector<int>&job, vector<vector<int>>&dp ){
        
        if( idx == job.size() ){
            if( d == 0 )    return 0 ;
            return 1e9 ;
        }  
        
        if( d == 0 )    return 1e9 ;
        
        if( dp[idx][d] != -1 ) return dp[idx][d] ;
        
        int ans = INT_MAX , maxi = INT_MIN ;
        
        for( int i = idx ; i < job.size() ; i++ ){
            
            maxi = max( maxi, job[i] ) ;
			
            int temp = maxi + solve(i+1, d-1, job, dp) ;
			
            ans = min(temp, ans) ;
			
        }
        return dp[idx][d] = ans ;
    }
    
    
    int minDifficulty(vector<int>& job, int d) {
	
        int n = job.size() ;
        
        vector<vector<int>>dp(n+1, vector<int>(d+1, -1)) ;
        
        int ans = solve(0, d, job, dp) ;
        
        if( ans >= 1e9 )    return -1 ;
        
        return ans ;
        
    }
};