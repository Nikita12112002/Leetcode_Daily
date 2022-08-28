class Solution {
public:
    // brute force 
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        
         int n = arr.size();
    sort(arr.begin(), arr.end());
    vector <vector<int>> ans;
 
    for (int i = 0; i < n; i++) {
        int start = arr[i][0], end = arr[i][1];
          vector<int>res;
        //since the intervals already lies 
        //in the data structure present we continue
        if (!ans.empty()) {
            if (start <= ans[ans.size()-1][1]) {
                continue;
            }
        }

        for (int j = i + 1; j < n; j++) {
            if (arr[j][0] <= end) {
                end = max(end, arr[j][1]);
            }
        }
    
        // end = max(end, arr[i][1]);

       res.push_back(start);
       res.push_back(end);
        
        ans.push_back(res);
    }

    return ans;
        
    }
};