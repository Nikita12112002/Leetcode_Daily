// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

bool static comp(Job j1 , Job j2)
{
    if(j1.profit>j2.profit)
    return true;
    
    else return false;
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<int>ans;
        
        // sort the array acc to descending order of profit.
        sort(arr,arr+n,comp);
        
        int maxi=0 , count=0;
        
        // find out the maximum deadline among all the jobs
        for(int i=0 ;i<n;i++)
        {
             maxi=max(maxi,arr[i].dead);
        }
        
        // make an array of size equal to max 
        //deadline and intialize it with one
        int a[maxi];
        
        for(int i=1 ;i<=maxi ;i++)
        {
            a[i]=-1;
        }
        int profit =0;
        
        // major portion
      
        for(int i=0 ;i<n;i++)
        {
            for(int j=arr[i].dead ; j>0 ;j--)
            {
                if(a[j]==-1)
                {
                    count++;
                    a[j]=i;
                    profit = profit + arr[i].profit;
                    break;
                }
            }
        }
        
        ans.push_back(count);
        ans.push_back(profit);
        return ans;
    }
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends