class Solution {
public:
    int minCostClimbingStairs(vector<int>& costs) {
        
        //space optimization code through dp. 
        
        int n=costs.size() ;
        int prev1=costs[0],prev2=costs[1] ,mini=0;
        
        
        
        if(n==0)
            return 0;
        
        if(n==1)
            return costs[0];
        
        for(int i=2 ;i<n;i++)
        {
            mini=min(prev1,prev2)+costs[i];
            prev1=prev2;
            prev2=mini;
        }
        return min(prev1,prev2);
    }
};