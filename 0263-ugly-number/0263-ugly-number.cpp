class Solution {
public:
    bool isUgly(int n) {
        
        if(n<=0)
            return false;
        
        for(int i=2 ;i<n; i++)
        {
            if(n%2==0)
            {
            while(n%2==0)
            {
                n=n/2;
            }
            }
            
           else if(n%3==0)
            {
            while(n%3==0)
            {
                n=n/3;
            }
            }
            
           else if(n%5==0)
            {
            while(n%5==0)
            {
                n=n/5;
            }
            }
            
            else
                return false;
        }
        return true;
    }
};