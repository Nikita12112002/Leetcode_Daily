class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        sort(horizontalCuts.begin() , horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        int n = horizontalCuts.size();
        int m = verticalCuts.size();
        long long  p,q;
        
            p=max(horizontalCuts[0],h-horizontalCuts[n-1]);
       
         for(int i=1 ;i<n ;i++)
         {
            long long a= (long)horizontalCuts[i]-horizontalCuts[i-1];
             p=max(p,a );
         }
           
       
            q= max(verticalCuts[0] , w-verticalCuts[m-1]);
        
      for(int i=1 ;i<m ;i++)
      {
          long long b=(long)verticalCuts[i]-verticalCuts[i-1];
          q=max(q,b );
      }
           
          return (int)((long)p * q % 1000000007);
        
        // int maxh = max(hc[0], h - hc.back()),
        //     maxv = max(vc[0], w - vc.back());
        // for (int i = 1; i < hc.size(); i++)
        //     maxh = max(maxh, hc[i] - hc[i-1]);
        // for (int i = 1; i < vc.size(); i++)
        //     maxv = max(maxv, vc[i] - vc[i-1]);
        // return (int)((long)maxh * maxv % 1000000007);
        
    }
};