class Solution {
public:
    int subarraySum(vector<int> &nums, int k){
        unordered_map<int,int> um;
        um[0] = 1;
        int curr = 0;
        int ans = 0;
        for(auto it: nums){    
            curr += it;
            int rem = curr-k;
            if(um.find(rem) != um.end()){
                ans += um[rem];
            }
            um[curr] += 1;
        }
        return ans;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0;
		
        for(int i=0; i<matrix.size(); i++)
        {
			
            vector<int> sum(matrix[0].size(), 0);
            
            for(int j=i; j<matrix.size(); j++)
            {
                for(int k=0; k<matrix[0].size(); k++)
                {
                    sum[k] += matrix[j][k];
                }
				
                
                ans += subarraySum(sum, target);
            }
        }
        
        return ans;
    }
};