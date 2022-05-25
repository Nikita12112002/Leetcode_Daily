class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      //brute force sol -- using xor   
        int ans=nums[0];
        
        for(int i=1 ;i<nums.size() ;i++)
        {
            ans=ans^nums[i];
        }
        return ans;
    }
};