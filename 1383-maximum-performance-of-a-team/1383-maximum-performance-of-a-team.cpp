class Solution {
public:
    long long mod=10000000007;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
//         priority_queue<pair<long,long>>q;
//         priority_queue<long,vector<long>,greater<long>>q2;
        
//         long sum=0;
//         long  maxi=0;
        
//         for(int i=0;i<n;i++)
//         {
//             q.push({efficiency[i],speed[i]});
//         }
        
//         while(!q.empty())
//         {
//             auto top = q.top();
//             q.pop();
            
//             sum = sum+top.second;
             
//             q2.push(top.second);
            
//             if(q2.size()>k)
//             {
//                 sum=sum-q2.top();
//                 q2.pop();
//             }
           
            
//             maxi = max(maxi,top.first*sum);
//         }
//        return maxi% (int)mod; 
        
        vector<pair<int,int>> perf(n);
        for(int i=0;i<n;i++)
        {
            perf[i]={efficiency[i],speed[i]};
        }
        
        //sort the perf in descending order
        sort(rbegin(perf),rend(perf));
        
        //priority queue to get the smallest sum 
        priority_queue<int,vector<int>,greater<int>> pq; //min heap
        long sum=0;
        long  res=0;
        for(auto [eff,speed] : perf)
        {
            sum+=speed;
			//push the current speed to the pq
            pq.push(speed);
            if(pq.size()>k)
            {
                //remove the smallest speed
                sum-=pq.top();
                pq.pop();
            }
			//since eff is the currents small efficiency 
            res=max(res,sum*eff);
        }
        return res % (int)(1e9+7);
    
    }
};