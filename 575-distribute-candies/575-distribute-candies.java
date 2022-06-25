class Solution {
    public int distributeCandies(int[] candyType) {
        
        HashMap<Integer,Integer>m = new HashMap<>();
        
        for(int i=0 ;i<candyType.length ;i++)
        {
            if(!m.containsKey(candyType[i]))
                m.put(candyType[i],1);
            
            else
                m.put(candyType[i],m.get(candyType[i])+1);
        }
        
        if(m.size()<candyType.length/2)
             return m.size();
        
        else
          return candyType.length/2;
        
    }
}