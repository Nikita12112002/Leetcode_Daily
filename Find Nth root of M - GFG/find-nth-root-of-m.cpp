// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
// 		int multi(int number , int n)
// 	{
// 	    int ans=1;
// 	    for(int i=1 ;i<=n;i++)
// 	    {
// 	        ans=ans*number;
// 	    }
	    
// 	    return ans;
// 	}
	
	int NthRoot(int n, int m)
	{
	    
	    // Code here.
	   // int low=1 , high=m;
	    
	   // while(low<=high)
	   // {
	   //     int mid = (low+high)/2;
	        
	   //     if(multi(mid,n)==m)
	   //       return mid;
	        
	   //     if(multi(mid,n)<m)
	   //      low=mid+1;
	         
	   //      else
	   //       high=mid-1;
	   // }
	    
	   // return -1;
	    
	     // Code here.
    int start=1;
    int end=m;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(pow(mid,n)==m)
        {
            return mid;
        }
        else if(pow(mid,n)>m)
        {
            end=mid-1;
        }
        else if(pow(mid,n)<m)
        {
            start=mid+1;
        }
         
    }
    return -1;
	}  
	

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends