class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>>ans(n,vector<int>(n,0));
        long long count=1,m=n;
        long long low=0 ,high=n-1;
      while(1)
      {
          
         if(n*n<count)
              break;
          
        for(int j=low ;j<=high ;j++) // first row
        {
            ans[low][j]=count;
            count++;
        }
        
        for(int i=low+1 ;i<=high;i++)//last col
        {
            ans[i][high]=count;
            count++;
        }
        
        for(int j=high-1;j>=low ;j--) // last row
        {
            ans[high][j]=count;
            count++;
        }
        
        for(int i=high-1 ;i>=low+1 ;i--) //first col
        {
            ans[i][low]=count;
            count++;
        }
          
//           cout<<count<<endl;
        
           
       low++;   //These two statements signifies that
                //matrix is reduced 
       high--;
        
          
      }
       return ans; 
    }
};