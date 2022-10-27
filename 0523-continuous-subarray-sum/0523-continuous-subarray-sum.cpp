class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int>m;
    
        long long sum=0;
        
        for(int i=0 ;i<nums.size();i++)
        {
            sum=sum+nums[i];
            if(sum%k==0)
            {
                if(i>0)
                    return true;
            }
            int rem = sum%k;
            
            if(m.find(rem)!=m.end())
            {
                if(i-m[rem] >1)
                {
                    return true;
                }
             
            }
            else
            {
                m[rem]=i;
            }
        }
        
        return false;
    }
};