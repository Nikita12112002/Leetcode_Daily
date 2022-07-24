class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        //variation of binary search
        //TC-O(n+m);
        
        int n=matrix.size();
        int row=0,col=matrix[0].size()-1;
        
        while(row<n && col>=0)
        {
            if(matrix[row][col]==target)
                return true;
            
            else if(matrix[row][col]>target)
                col--;
            else
                row++;
        }
        return false;
    }
};