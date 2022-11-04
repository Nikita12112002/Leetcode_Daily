class Solution {
public:
    string reverseVowels(string s) {
        
        vector<char>ans(s.length());
        
        for(int i=0 ; i<s.length() ;i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' ||  s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            {
                
                ans.push_back(s[i]);
            }
        }
        
        reverse(ans.begin(),ans.end());
        int k=0;
        for(int i=0 ;i<s.length() ;i++)
        {
            
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' ||  s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            {
                
                s[i]=ans[k];
                k++;
            }
        }
        
        return s;
    }
};