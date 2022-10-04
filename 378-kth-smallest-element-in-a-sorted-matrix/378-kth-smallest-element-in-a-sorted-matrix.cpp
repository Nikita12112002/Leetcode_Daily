class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        priority_queue<int,vector<int>,greater<int>>q;
        
         for(int i=0 ;i<matrix.size();i++)
         {
             for(int j=0 ;j<matrix[0].size();j++)
             {
                 q.push(matrix[i][j]);
             }
         }
        
        int i=1;
        while(!q.empty())
        {
            if(i==k)
                return q.top();
            q.pop();
            i++;
        }
        
        return -1;
    }
};