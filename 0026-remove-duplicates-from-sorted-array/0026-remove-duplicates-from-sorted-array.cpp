class Solution {
public:
    // TC:O(n) SC:O(1)
    int removeDuplicates(vector<int>& nums) {
   
     int i=0, j;
        
        for(j=1 ;j<nums.size();j++)
        {
            if(nums[i]!=nums[j])
               
            {
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};