class Solution {
public:
    string makeGood(string s) {
       int n=s.size();
					
					if(s.size()==0)
						return "";
					if(s.size()==1)
						return s;
					for(int i=0;i<s.size();++i)
					{
						if(abs(s[i]-s[i+1])==32)
						{
							s.erase(i,2);
                            cout<<s<<" ";
							if(i==0)
								i--;
							else
								i-=2;
                            
						}    
					}
					return s;
    }
    
};