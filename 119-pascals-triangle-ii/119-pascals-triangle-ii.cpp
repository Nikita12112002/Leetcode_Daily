class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        long long val=1;
        vector<int>ans;
        for(long long i=0 ;i<rowIndex+1 ;i++)
        {
            ans.push_back(val);
            val =val*(rowIndex-i)/(i+1);
        }
       return ans; 
    }
};