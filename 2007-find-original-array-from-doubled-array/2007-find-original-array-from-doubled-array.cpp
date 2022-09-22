class Solution {
public:
    vector<int> findOriginalArray(vector<int>&nums) {
        
        sort(nums.begin(),nums.end());
        unordered_map<int,int>m;
        vector<int>ans;
        
        if(nums.size()%2!=0)
            return {};
        for(int i=0 ;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        
            
        for(int i=0 ; i<nums.size();i++)
        {
            if(m[nums[i]]!=0)
            {
               if(m[nums[i]*2]!=0)
              {
                ans.push_back(nums[i]);
                m[nums[i]*2]--;
                m[nums[i]]--;
              }
            
              else
                  return {};
            }
            
        
        }
       return ans; 
    }
};