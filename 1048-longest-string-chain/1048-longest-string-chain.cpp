class Solution {
public:
    bool compare_strings(string& a , string& b)
    {
        if(a.size()-b.size()!=1) 
            return false;
        
        int i=0 , j=0;
        while(i<a.size()) // we know a is larger 
        {
            if( j< b.size() && a[i]==b[j])
            {
                i++;
                j++;
            }
            else
                i++;
        }
        
        if( j==b.size())
            return true;
        return false;
    }
    
    bool static comp(string &a , string &b)
    {
        return a.size()<b.size();
    }
    
//     bool compare_strings(string& s1, string& s2){
//     if(s1.size() != s2.size() + 1) return false;
    
//     int first = 0;
//     int second = 0;
    
//     while(first < s1.size()){
//         if(second < s2.size() && s1[first] == s2[second]){
//             first ++;
//             second ++;
//         }
//         else first ++;
//     }
//     if(first == s1.size() && second == s2.size()) return true;
//     else return false; 
// }

// bool static comp(string& s1, string& s2){
//     return s1.size() < s2.size();
// }

    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),comp);
        int n = words.size();
        vector<int>dp(n,1);
        
        for(int i=0 ; i<n ;i++)
        {
            for(int prev=0 ; prev<i ;prev++)
            {
                if(compare_strings(words[i],words[prev]) && 1+dp[prev]>dp[i])
                {
                    dp[i]= 1+dp[prev];
                }
            }
        }
        
        int  ans=-1;
        for(int i=0 ;i<n ;i++)
        {
            if(dp[i]>ans)
            {
                ans=dp[i];
                
            }
        }
        
        return ans;
    }
};