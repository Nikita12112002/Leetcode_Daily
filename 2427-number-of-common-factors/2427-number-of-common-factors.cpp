class Solution {
public:
  
    int commonFactors(int a, int b) {
        
        int n = gcd(a,b);
        int count=0;
        for(int i=1;i<=n;i++)
        {
            if(n%i==0)
                count++;
        }
        return count;
        
          
    }
};