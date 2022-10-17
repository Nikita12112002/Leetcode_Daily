class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        
     
        for(int i=0;i<=num;i++)
        {
            int val=i;
            int c=0;
            while(val!=0)
            {
                c=(c*10)+(val%10);
                val=val/10;
            }
            
            int sum = i+c;
            if(sum==num)
                return true;
        }
        
        return false;
    }
};