class Solution {
public:
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
       priority_queue<pair<int,int>>q;
        priority_queue<int,vector<int>,greater<int>>q2;
        
        long sum=0;
        long  maxi=0;
        
        for(int i=0;i<n;i++)
        {
            q.push({efficiency[i],speed[i]});
        }
           
        
       while(!q.empty())
        {
            auto top = q.top();
            q.pop();
            
            sum = sum+top.second;
             
            q2.push(top.second);
            
            if(q2.size()>k)
            {
                sum=sum-q2.top();
                q2.pop();
            }
           
            
            maxi = max(maxi,sum*top.first);
        }
       return maxi% (int)(1e9+7); 
      
    
    }
};