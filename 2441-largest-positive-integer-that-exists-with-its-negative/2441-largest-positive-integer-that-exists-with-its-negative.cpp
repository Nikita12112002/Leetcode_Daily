class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        sort(nums.begin(),nums.end(),greater<int>());
        unordered_map<int,int>m;
        
        int n=nums.size();
        
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(m.find(-nums[i])!=m.end())
                return nums[i];
        }
        
        return -1;
    }
};