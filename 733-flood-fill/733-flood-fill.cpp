class Solution {
public:
    
    void dfs(vector<vector<int>>&image , int i , int j , int color ,  int intial)
    {
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size())
           return;
        
        if(image[i][j]!=intial)
            return;
        
        if(image[i][j]==color)
            return;
        
        image[i][j]=color;
        
        dfs(image,i-1,j,color,intial);
        dfs(image,i+1,j,color,intial);
        dfs(image,i,j-1,color,intial);
        dfs(image,i,j+1,color,intial);
        
        return;
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
     // can be solved using bfs and dfs too
        
        int n = image.size();
        int m =image[0].size();
        
       
        dfs(image,sr,sc,color,image[sr][sc]);
        return image;
        
    }
};