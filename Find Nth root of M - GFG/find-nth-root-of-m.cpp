// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
		int multi(int number , int n)
	{
	    int ans=1;
	    for(int i=1 ;i<=n;i++)
	    {
	        ans=ans*number;
	    }
	    
	    return ans;
	}
	
	int NthRoot(int n, int m)
	{
	    
	   // Code here.
	    int low=1 , high=m;
	    
	    while(low<=high)
	    {
	        int mid = (low+high)/2;
	        
	        if(pow(mid,n)==m)
	          return mid;
	        
	        if(pow(mid,n)<m)
	         low=mid+1;
	         
	         else
	          high=mid-1;
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