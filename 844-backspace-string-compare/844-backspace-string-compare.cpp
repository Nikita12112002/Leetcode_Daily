class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        
        for(int i=0 ;i<n ;i++)
        {
            if(s[i]=='#')
            {
                if(i==0)
                {
                    s.erase(s.begin()+i);
                    i--;
                }
                else
                {
                int c=i-1;
                
                s.erase(s.begin()+i);
                s.erase(s.begin()+c);
                i=i-2;
                }
            }
            
        }
       
         for(int i=0 ;i<m ;i++)
        {
            if(t[i]=='#')
            {
                if(i==0)
                {
                    t.erase(t.begin()+i);
                    i--;
                }
                
               else
               {
                int c=i-1;
                
                t.erase(t.begin()+i);
                t.erase(t.begin()+c);
                i=i-2;
               }
            }
            
        }
       
        if(s==t)
        return true;
        
        return false;
        
    }
};