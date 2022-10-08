class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int mini=INT_MAX;
        int ans=0;
        int n = nums.size();
        
        for(int i=0 ;i<n;i++)
        {
            int j=i+1,k=n-1;
            
            while(j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                
                if(abs(target-sum)<mini)
                {
                    mini=abs(target-sum);
                    ans=sum;
                }
                
                else if(sum>target)
                    k--;
                else
                    j++;
            }
            
        }
        
        return ans;
    }
};