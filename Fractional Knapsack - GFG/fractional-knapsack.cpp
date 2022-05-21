// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
    public:
    
      bool static comp(Item ele1, Item ele2) {
         double s1 = (double) ele1.value / (double) ele1.weight;
         double s2 = (double) ele2.value / (double) ele2.weight;
         return s1 > s2;
      }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
       
        sort(arr,arr+n,comp);
        
        int weight=0 ;
        double profit=0.0;
        
        for(int i=0 ; i<n ;i++)
        {
            if(weight+arr[i].weight <=W)
            {
                weight = weight+arr[i].weight;
                profit= profit+arr[i].value;
            }
            
            else
            {
                int rem = W-weight;
                profit=profit+(arr[i].value/(double)arr[i].weight)*(double)rem;
                break;
            }
        }
        
        return profit;
    }
    
    
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends