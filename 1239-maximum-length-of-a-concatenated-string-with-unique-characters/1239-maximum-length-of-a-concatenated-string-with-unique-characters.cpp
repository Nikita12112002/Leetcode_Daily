class Solution {
public:
    
    int len=0;
    
    bool isunique(string& s)
    {
        if(s.length()==0)
            return true;
        set<char>st;
        for(int i=0 ; i<s.length();i++)
        {
            if(st.find(s[i])!=st.end())
                return false;
            st.insert(s[i]);
        }
        
        return true;
    }
    void dfs(vector<string>&arr , string str , int i)
    {
        if(isunique(str)==false)
            return;
        
        if(str.length()>=len)
        {
            len = str.length();
        }
        
        for(int j=i ;j<arr.size();j++)
        {
            dfs(arr,str+arr[j],j+1);
        }
       return;     
    }
    int maxLength(vector<string>& arr) {
        
         dfs(arr,"",0);
        return len;
    }
};