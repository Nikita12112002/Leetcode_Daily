class Solution {
public:
    bool isAnagram(string s, string t) {
       
     unordered_map<char,int>m;
        
        if(s.length()!=t.length())
            return false;
        
        for(int i=0 ;i<s.length();i++)
        {
            m[s[i]]++;
        }
        
        for(int i=0 ;i<t.length() ;i++)
        {
            if(m[t[i]]>0)
                
                m[t[i]]--;
            
        }
        
        for(auto it:m)
        {
            if(it.second>0)
                return false;
        }
        
        return true;
    }
};