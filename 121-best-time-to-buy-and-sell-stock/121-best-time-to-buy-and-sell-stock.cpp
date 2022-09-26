class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mini=prices[0] , maxi =0;
        for(int i=1 ;i<prices.size() ;i++)
        {
            if(prices[i]<mini)
                mini=prices[i];
            
            else if(maxi<prices[i]-mini)
            {
                maxi=max(maxi , prices[i]-mini);
            }
        }
        return maxi;
    }
};