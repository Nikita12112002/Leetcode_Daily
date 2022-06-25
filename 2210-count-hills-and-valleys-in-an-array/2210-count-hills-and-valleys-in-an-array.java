class Solution {
    public int countHillValley(int[] nums) {
        
        int count=0,j=0;
        
        for(int i=1 ;i<nums.length-1 ;i++)
        {

                if(nums[i]>nums[j] && nums[i]>nums[i+1])
                {
                    count++;
                    j=i;
                }
                
                
                else if(nums[i]<nums[j] && nums[i]<nums[i+1])
                {
                    count++;
                    j=i;
            
                }
        }
        return count;
    }
}