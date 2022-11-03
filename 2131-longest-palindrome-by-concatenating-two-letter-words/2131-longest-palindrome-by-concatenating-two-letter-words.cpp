class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        unordered_map<string,int>mp;
        long long ans=0;
        
        for(string x:words)
        {
            string y=x;
            reverse(y.begin(),y.end());
            
            if(mp.find(y)!=mp.end())
            {
                ans+=4;
                mp[y]--;
                
                if(mp[y]==0){
                    mp.erase(y);
                }
                
            }
            else{
                mp[x]++;
            }
        }
        for(auto x:mp)  
        {
            if(x.first[0]==x.first[1]){ // we are breaking in the first time only bcoz all the elements remaining will have one freq ,so there can only be one element added in the string to make it palindrome.
                ans+=2;
                break;
            }
        }
        
        
        return ans;
        
    }
    
};