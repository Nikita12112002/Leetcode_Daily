class Solution {
public:
    // Moores Voting Algorithm TC:O(n) SC:O(1)
    int majorityElement(vector<int>& nums) {
        
        int count=0 , ele=0;
        
        for(int i=0 ;i<nums.size();i++)
        {
            if(count==0)
                ele=nums[i];
            
            if(ele==nums[i])
                count++;
            
            else
                count--;
        }
        return ele;
    }
};