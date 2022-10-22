class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int>m;
        int ans = INT_MAX;
        int start=0 , count=0 ,i,j;
        
        if(s.empty() || t.empty())
        {
           return "";
        }  
          
        else if(s.length()<t.length())
        {
            return "";
        }
            
        else{
            
        for(i=0 ; i<t.length() ;i++)
        {

            if(m[t[i]]==0)
            {

                
                count++;
            }
            
            m[t[i]]++;
        }
        
    i=0;
    j=0;
        
        while(j<s.length())
        {
            
                m[s[j]]--;
                
                if(m[s[j]]==0)
                {
                   count--;
                }
                
                if(count==0)
                {
                    while(count==0)
                    {
                        if(ans>j-i+1)
                        {
                            ans=min(ans,j-i+1);
                            start=i;
                            
                        }
                        
                        m[s[i]]++;
                        
                        if(m[s[i]]>0)
                        {
                            count++;
                        }
                        
                        i++;
                     }
                    

                }
                
                j++;
            }
            
        } 
    
          if(ans!=INT_MAX)
              return s.substr(start,ans);
          else
              return "";
        
        
        
    }
};