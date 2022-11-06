class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        if(k>1)
        {
            sort(s.begin(),s.end());
            return s;
        }
        int n = s.length();
        string ans = s+s;
        string res=s;
        for(int i=1 ;i<n ;i++)
        {
            string str = ans.substr(i,n);
            
            if(str<res)
            {
                res =str;
            }
        }
        return res;
    }
};