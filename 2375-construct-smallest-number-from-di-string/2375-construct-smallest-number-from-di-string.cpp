class Solution {
public:
    string smallestNumber(string pattern) {
        
        int n=pattern.size();
        string s = "";
        
        for(int i=0 ;i<=n ;i++)
            s= s + to_string(i+1);
        
        int j=0;
        for(int i=0 ; i<=pattern.size() ;i++)
        {
            if(pattern[i]=='D')
            {
                while(i<pattern.size() && pattern[i]=='D')
                    i++;
                
                reverse(s.begin()+j , s.begin()+i+1);
            }
            
            j=i+1;
        }
        return s;
    }
};