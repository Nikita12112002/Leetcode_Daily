class Solution {
    public int countPrefixes(String[] words, String s) 
    {
        int count=0;
        for(String val:words)
        {
            if(s.startsWith(val))
                count++;
            
        }
         
        return count;
    }
}