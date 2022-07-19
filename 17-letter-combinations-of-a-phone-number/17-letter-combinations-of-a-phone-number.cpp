class Solution {
public:
      unordered_map<char,string>m;
    
    void dfs(int i,vector<string>&ans,int n  ,string curr,string digits)
    {
        if(curr.length()==n)
        {
            if(curr!="")
            ans.push_back(curr);
            return;
        }
        
         string s=m[digits[i]];
        
        for(int j=0 ;j<s.length();j++)
        {
            curr=curr+s[j];
            
            dfs(i+1,ans,n,curr,digits);
            curr.pop_back();
            
           
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        vector<string>res;
      
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        
        dfs(0,ans,digits.size() ,"",digits);
        
        return ans;
    }
};