class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        long long n = nums.size();
        
        vector<int>ans;
        
        long long s=(n*(n+1))/2 ,p=(n*(n+1)*((2*n)+1))/6;
        
        for(long long i=0 ;i<n ;i++)
        {
           s=s-(long long)nums[i];
           p=p- (long long)(nums[i]*nums[i]);
        }
        
        long long  missing = (s+(p/s))/2;
        long long repeating = missing-s;
        
        ans.push_back(repeating);
        ans.push_back(missing);
        return ans;
    }
};