class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        
        HashMap<Character,Integer>m=new HashMap<>();
        int count=0;
        
        for(int i=0 ;i<stones.length() ;i++)
        {
            if(!m.containsKey(stones.charAt(i)))
                m.put(stones.charAt(i),1);
            
            else
                m.put(stones.charAt(i),m.get(stones.charAt(i))+1);
        }
        
        for(int i=0 ;i<jewels.length() ;i++)
        {
            if(m.containsKey(jewels.charAt(i)))
            {
                Integer a = m.get(jewels.charAt(i));
                
                count=count+a;
            }
                
        }
        return count;
    }
}