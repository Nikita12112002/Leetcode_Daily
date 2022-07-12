class Solution {
public:
    bool makesquare(vector<int>& match) {
     
     int n = match.size(),sum=0;
        
     if(n<4)
         return false;
        
     for(int i=0 ;i<n;i++)
         sum=sum+match[i];
    
     int perimeter = sum/4;
        
      vector<int>sides(4,0);
      sort(match.begin(),match.end(),greater<int>());  
      return dfs(match,sides,perimeter,0);
    }
    
    bool dfs(vector<int>match , vector<int>&sides ,int perimeter, int index)
    {
      if(index==match.size()) 
      {
          if(sides[0]== sides[1] && sides[1]==sides[2] && sides[2]==sides[3])
              return true;
          return false;
      }
      
        for(int i=0 ;i<4;i++)
        {
            if(sides[i]+match[index]>perimeter)
                continue;
            
            int j=i-1;
            while(j>=0)
            {
                if(sides[j]==sides[i]) //if we have already computed same array as before we will break (dp is used ..check previous computed things)
                    break;
                j--;
            }
            
            if(j!=-1)
                continue;
            sides[i]=sides[i]+match[index];
            
            if(dfs(match,sides,perimeter,index+1))
                return true;
            
            sides[i]=sides[i]-match[index];
        }
        return false;
    }
};