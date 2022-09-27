#define ll long long
class Solution {
public:
    
    class comp {   
    public:
        bool operator()(string &a, string &b) {      // Like min heap first greater then, smaller nums on top
            return a.length() > b.length() || (a.length()==b.length() && a>b);
        }
    };
    
    
    string kthLargestNumber(vector<string>& nums, int k) {
        
        ll n= nums.size();
        priority_queue<string, vector<string>, comp> pq;        // Min heap with custom comparator
        
        for(ll i=0; i<n; i++) {
            pq.push(nums[i]);
        }
        
        while(pq.size() > k) {
            pq.pop();
        }
        
        return pq.top();
    }
    

    // uuper vala solution iss neeche diye gye solution ka explanatory version maan sktay h...kyuki dono n kaam ek hi kiya h bs ek n compartaor bnaya aur dusre n pair pr work dono method ekdum same kregay...
    // explanation pure code ka comparater m hi chupa hua h
    
//     string kthLargestNumber(vector<string>& nums, int k) {
//         priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
//         for(auto it: nums){
//             int len=it.size();
//             pq.push({len, it});
//             if(pq.size()>k) pq.pop();
//         }
//         return pq.top().second;
// }
};