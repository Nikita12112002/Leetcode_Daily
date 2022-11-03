class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char,int>m;
        int ans=0;
        for(int i=0 ;i<s.length();i++)
        {
            m[s[i]]++;
        }
        
        for(auto it:m)
        {
            if(it.second%2==0)
            {
                ans=ans+it.second;
            }
            else
            {
                ans=ans+(it.second-1);
                m[it.first]=1;
            }
        }
        
        for(auto it:m)
        {
            if(it.second==1)
            {
                ans=ans+1;
                break;
            }
        }
        return ans;
    }
};