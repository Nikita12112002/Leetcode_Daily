class Solution {
public:
    bool isPalindrome(int x) {
        
        // without using extra space.
        
        if(x<0)
            return false;
        
        long long y=x , num=0;
        
        while(x>0)
        {
             num = num*10;
            num=num+(x%10);
            x=x/10;
        }
        
        if(num==y)
            return true;
        else
            return false;
    }
};