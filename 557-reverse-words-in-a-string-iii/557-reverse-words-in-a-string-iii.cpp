class Solution {
public:
    string reverseWords(string s) {
        
        string temp="",ans="";
        for(int i=0 ;i<s.length();i++)
        {
            if(i==s.length()-1)
            {
              temp=temp+s[i];
            }
            else if(s[i]!=' ')
            {
                temp=temp+s[i];
                continue;
            }
            
            reverse(temp.begin(),temp.end());
            ans=ans+temp;
            
            if(i!=s.length()-1)
                ans=ans+' ';
                
            temp="";
        }
        return  ans;
    }
};