class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size() , flag=0;
        
        int i , count=0 , ans=0;
        
        if(n==1)
        {
            return 0;
        }
        
       
        for(i=1 ; i<n ;i++)
        {
           count=0;   
            if(nums[i]<=nums[i-1])
            {
                count=  nums[i-1]-nums[i]+1;
                ans= ans + count;
                nums[i]=count + nums[i];
            }
        }
        return ans;
        
        
          
        
    }
};