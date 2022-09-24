class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin(),tokens.end());
        int n = tokens.size();
        int i=0 ,j=n-1;
        int score=0;
        int maxi=0;
        
        while(i<=j)
        {
            if(power>=tokens[i])
            {
                power=power-tokens[i];
                score++;
                i++;
                 maxi=max(maxi,score);
            }
            
            else if(score>=1)
            {
                power=power+tokens[j];
                score--;
                j--;
            }
            else
                break;
        }
        
        return maxi;
    }
};