class Solution {
public:
    string breakPalindrome(string palindrome) {
        
        if(palindrome.length()==1)
            return "";
        int n = palindrome.size();
        
        for(int i=0 ; i<n/2 ;i++)
        {
            if(palindrome[i]!='a')
            {
                palindrome[i]='a';
                return palindrome;
                    
            }
        }
        palindrome[n-1]='b';
        return palindrome;
    }
};