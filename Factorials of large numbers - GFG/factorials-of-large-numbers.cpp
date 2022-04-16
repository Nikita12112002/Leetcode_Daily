// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
  
        // code here
        vector<int> factorial(int n){
   // code here
   vector<int>digits;
   int val;

   for (int i =1;i<=n;i++){
       int j =0;
       int carry = 0;
       if (i==1){
           digits.push_back(1);
           continue;
       }
       while(j<digits.size()){
           val = digits[j]*i + carry;
           digits[j]= val%10;
           carry = val/10;
           j++;
       }

       while(carry!=0){
           digits.push_back(carry%10);
           carry=carry/10;
       }
   }
   reverse(digits.begin(),digits.end());
   return digits;
   }
    
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends