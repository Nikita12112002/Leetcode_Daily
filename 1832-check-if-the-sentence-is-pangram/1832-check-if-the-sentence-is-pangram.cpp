class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        if(sentence.length()<26)
            return false;
        
        else
        {
            unordered_map<char,int>m;
            
            for(int i=0;i<sentence.length();i++)
            {
                m[sentence[i]]++;
            }
            
            for(char c='a' ; c<='z';c++)
            {
                if(m.find(c)==m.end())
                    return false;
            }
            
        }
        
        return true;
    }
};