class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int ans = 0;
        mp[0] = 1;      //edge case for algorithm
        
        long long sum = 0;

        for(int i =0; i<n; i++){
            sum+= nums[i];
            int rem = sum%k;
            
            //for negative cases
            if(rem<0) rem+=k;
                
            ans+= mp[rem];
            mp[rem]++;            
        }
        
        return ans;
        
    }
};