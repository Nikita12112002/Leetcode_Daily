class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int>v1,v2;
        vector<int>ans;
        for(int i=0 ;i<nums.size() ;i++)
        {
            if(nums[i]>0)
                v1.push_back(nums[i]);
            
            else if(nums[i]<0)
                v2.push_back(nums[i]);
        }
        
        int i=0,j=0,k=0;
        while(i<v1.size()||j<v2.size())
        {
            if(k%2==0)
            {  nums[k]=v1[i];
               i++;
               k++;
            }
            
            else
            { nums[k]=v2[j];
             k++;
             j++;
            }
            
        }
        
        return nums;
    }
};