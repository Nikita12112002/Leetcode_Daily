// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool allocationPossible(int arr[],int barrier,int k,int n){
        int allocatedStudents=1;   //STUDENTS ALLOCATED INITIALLY TAKE AS 1 STUDENT
        int pages=0;                // PAGE SUM 
        
        for(int i=0;i<n;i++){       
            if(arr[i]>barrier)      //CHECK WHETHER THE FIRST BOOK CAN EVEN BE ASSIGNED OR NOT
                return false;
            if(arr[i]+pages>barrier){       ////CHECK WHETHER THESE MANY BOOKS ASSIGNED COMES UNDER THE BARRIER OR NOT IF NOT THEN ASSIGN BOOKS TO NEW STUDENT
                allocatedStudents++;
                pages=arr[i];           //RESET THE NUMBERING FROM THE CURRENT BOOK
            }
            else{
                pages+=arr[i];          //NO ISSUES JUST KEEP ON ADDING THE BOOKS
            }
        }
        if(allocatedStudents>k)         //THE BOOKS ASSIGNMENT IS DONE TO K STUDENTS ONLY IF NOT THEN RETURN FALSE 
            return false;
        return true;                    //ELSE RETURN TRUE
    }
    int findPages(int arr[], int n, int k) 
    {
        if(k>n)                 //CHECK WHETHER K>N THEN RETURN -1
            return -1;
          int sum=0;  
    //   sort(arr,arr+n);
        
        
    //     for(int i=0 ;i<n ;i++)
    //     {
    //         sum=sum+arr[i];
    //     }
        int lo=arr[0];
        int hi=0;
        int res=-1;
        for(int i=0;i<n;i++){       //ASSIGN THE MINIMUM POSSIBLE VALUE TO LO AND SUM OF THE ARRAY TO HI
            hi+=arr[i];
            lo=min(lo,arr[i]);
        }
        while(lo<=hi){                  //APPLY BINARY SEARCH
            int mid=(lo+hi)>>1;         //CALCULATE THE MIDDLE VALUE
            if(allocationPossible(arr,mid,k,n)){        //CHECK WHETHER ALLOCATION OF BOOK IS POSSIBLE OR NOT
                res=mid;
                hi=mid-1;               //IF YES THEN REDUCE THE BOUNDARY BY NEGATING HIGH
            }
            else
            lo=mid+1;               //IF NO THEN INCREASE LOW
        }
        return lo;                  //RETURN FINAL ANS AS LO OR AS RES
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends