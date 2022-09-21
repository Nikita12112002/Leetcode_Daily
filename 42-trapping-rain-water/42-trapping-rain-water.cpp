class Solution {
public:
    int trap(vector<int>& nums) {
        
        int n = nums.size();
        int i=0 , j=n-1;
        int leftmax=0 , rightmax=0;
        int res=0;
        while(i<=j)
        {
            if(nums[i]<=nums[j])
            {
                if(nums[i]>=leftmax)
                    leftmax=nums[i];
                else
                    res = res+(leftmax-nums[i]);
                i++;
            }
            
            
           else 
            {
                if(nums[j]>=rightmax)
                    rightmax=nums[j];
                else
                    res = res+(rightmax-nums[j]);
                j--;
            }
        }
       return res; 
    }
};