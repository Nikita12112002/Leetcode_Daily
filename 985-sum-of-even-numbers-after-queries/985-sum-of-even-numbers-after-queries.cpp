class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        int sum=0 ,flag=0;
        for(int i=0 ; i<nums.size() ;i++)
        {
            if(nums[i]%2==0)
                sum=sum+nums[i];
        }
        
        vector<int>ans;
        for(int i=0 ;i<queries.size();i++)
        {
            flag=0;
            if(nums[queries[i][1]]%2==0)
                flag=1;
            int prev = nums[queries[i][1]];
            nums[queries[i][1]] = nums[queries[i][1]]+queries[i][0];
            
            if(flag==0 && nums[queries[i][1]]%2==0)
            {
                ans.push_back(sum+nums[queries[i][1]]);
                sum = sum + nums[queries[i][1]];
            }
            
           else if(flag==0 && nums[queries[i][1]]%2!=0)
            {
                ans.push_back(sum);
               sum =sum;
            }
            
            else if(flag==1 && nums[queries[i][1]]%2!=0)
            {
                
                ans.push_back(sum-prev);
                sum = sum-prev;
            }
            
             else if(flag==1 && nums[queries[i][1]]%2==0)
            {
                ans.push_back( sum + queries[i][0]);
                 sum = sum + queries[i][0];
            }

        }
       return ans; 
    }
};