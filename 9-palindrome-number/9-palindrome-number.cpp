class Solution {
public:
    bool isPalindrome(int x) {
     //using extra space;   
        vector<int>ans;
        
        if(x<0)
            return false;
        
        while(x!=0)
        {
            int rem=x%10;
            ans.push_back(rem);
            x=x/10;
        }
        
        for(int i=0 ;i<ans.size()/2;i++)
        {
            if(ans[i]!=ans[ans.size()-1-i])
                return false;
        }
        
        return true;
    }
};