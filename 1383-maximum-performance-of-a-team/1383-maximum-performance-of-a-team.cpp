class Solution {
public:
    int mod=10000000007;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int,int>>v;
        priority_queue<int,vector<int>,greater<int>>q2;
        
        long sum=0;
        long  maxi=0;
        
        for(int i=0;i<n;i++)
        {
            v.push_back({efficiency[i],speed[i]});
        }
           sort(v.rbegin(), v.rend());
        
       for(int i=0 ;i<v.size();i++)
        {
            
            
            sum = sum+v[i].second;
             
            q2.push(v[i].second);
            
            if(q2.size()>k)
            {
                sum=sum-q2.top();
                q2.pop();
            }
           
            
            maxi = max(maxi,sum*v[i].first);
        }
       return maxi% (int)(1e9+7); 
      
    
    }
};