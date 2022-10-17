class Solution {
public:
    
    int countDistinctIntegers(vector<int>& nums) {
        
        int n = nums.size();
        
         for(int i=0 ;i<n;i++)
         {
             int num=0;
             int val=nums[i];
             while(val!=0)
             {
               int rem = val%10;
               num=(num*10)+rem;
               val=val/10;
             }
            
             nums.push_back(num);
         }
        
        unordered_set<int>s;
        
        for (int i: nums)
        {
          
            s.insert(i);
        }
        return s.size();
    }

};
    
    