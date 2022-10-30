class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxi = nums[0];
        int mini = nums[0];
        int ans=nums[0];
        
        for(int i=1 ;i<nums.size();i++)
        {
            if(nums[i]<0) 
                swap(maxi,mini); //swapping is done because if any negative number comes then obviously when we multiply it with our prod then maxi will become minimum and mini will become maxi,that's why e swapped maxi and mini.
            
            maxi=max(nums[i],maxi*nums[i]);
            mini =min(nums[i],mini*nums[i]);
            
            ans=max(ans,maxi);
        }
        return ans;    
    }
};