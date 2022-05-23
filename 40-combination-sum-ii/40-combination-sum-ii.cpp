class Solution {
public:
    
    // In this ques there is a variation as compared to previous one 
    // we can use a element only once.
    // all the elements inside each combination in sorted order.
    // return the combination in  in lexographical sorted order
    // must not contain duplicate combinations
    
    void solve(int index,vector<int>& arr , int target ,vector<vector<int>>& ans,vector<int>& ds)
    {
        
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }
        
        for(int i = index;i<arr.size();i++) 
        {
            if(i>index && arr[i]==arr[i-1]) 
                continue; 
            
            if(arr[i]>target) 
                break; 
            
            ds.push_back(arr[i]);
           solve(i+1, arr,target - arr[i],  ans, ds); 
            ds.pop_back();  //backtracking step.
        }
        
    }
    
  
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(),candidates.end()); 
      vector<vector<int>>ans;
      vector<int>ds;
      solve(0,candidates,target,ans,ds);
      return ans;
    }
};

