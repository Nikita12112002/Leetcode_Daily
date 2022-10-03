class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
       priority_queue<pair<int,int> , vector<pair<int ,int>> , greater<pair<int,int>>>q;
        vector<int>ans;
        
        for(long long i=0 ;i<arr.size();i++)
        {
            q.push({ abs(x-arr[i]) , arr[i]});
        }
     
        
       while(!q.empty())
        {
            if(k>0)
            {
                k--;
                ans.push_back(q.top().second);
            }
            else
                break;
            q.pop();
        }
      sort(ans.begin(),ans.end());
        return ans;
    }
};