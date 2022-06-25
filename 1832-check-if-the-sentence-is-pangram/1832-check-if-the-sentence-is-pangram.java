class Solution {
    public boolean checkIfPangram(String sentence) {
        
      HashMap<Character,Integer>m = new HashMap<>();
        
        for(int i=0 ;i<sentence.length() ;i++)
        {
            if(!m.containsKey(sentence.charAt(i)))
            {
                m.put(sentence.charAt(i),1);
            }
            
            else
            
            m.put(sentence.charAt(i),m.get(sentence.charAt(i))+1);
        }
        
        for(char c ='a'; c<='z' ; c++)
        {
            if(!m.containsKey(c))
                return false;
        }
        
        return true;
    }
}