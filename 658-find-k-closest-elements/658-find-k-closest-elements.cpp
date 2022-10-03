class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<pair<long long,long long>>v;
        vector<int>ans;
        
        for(long long i=0 ;i<arr.size();i++)
        {
            v.push_back({ abs(x-arr[i]) , arr[i]});
        }
        sort(v.begin(),v.end());
        
        for(auto it:v)
        {
            if(k>0)
            {
                k--;
                ans.push_back(it.second);
            }
            else
                break;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};