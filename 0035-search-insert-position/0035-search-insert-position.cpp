class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       
        int n = nums.size();
        int low=0,high=n-1;
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        
        if(low==n)
            return n;
        return ans;
    }
};