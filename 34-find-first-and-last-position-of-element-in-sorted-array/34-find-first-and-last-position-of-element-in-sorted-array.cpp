class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<int>ans(2,-1);
        int low=0 , end=nums.size()-1 , res=-1;
  //first index      
        while(low<=end)
        {
            int mid = low+(end-low)/2;
            
            if(nums[mid]==target)
            {
                res=mid;
                end=mid-1;
            }
            
            else if(target>nums[mid])
                low=mid+1;
            else
                end=mid-1;
        }
        
        ans[0]=res;
        
          low=0 , end=nums.size()-1 , res=-1;
  //last index      
        while(low<=end)
        {
            int mid = low+(end-low)/2;
            
            if(nums[mid]==target)
            {
                res=mid;
                low=mid+1;
            }
            
            else if(target>nums[mid])
                low=mid+1;
            else
                end=mid-1;
        }
        
        ans[1]=res;
        
        return ans;
    }
};