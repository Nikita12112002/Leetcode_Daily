class Solution {
public:
    int maxResult(vector<int>& nums, int k)
    {
        int n=nums.size();
        vector<int>ans(n);
        priority_queue<pair<int,int>> pq;
        
        for(int i=n-1 ; i>=0 ; i--)
        {
            while(pq.size() && pq.top().second>i+k)
                pq.pop();
            
            ans[i]=nums[i];
            
            if(!pq.empty())
            {
                ans[i]=ans[i]+pq.top().first;
            }
           
            
            pq.push({ans[i], i});
        }
        
        return ans[0];
    }
};