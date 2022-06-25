class Solution {
    public int majorityElement(int[] nums) {
        
        HashMap<Integer,Integer>m=new HashMap<>();
        
        for(int i=0 ;i<nums.length ;i++)
        {
            if(!m.containsKey(nums[i]))
            {
                m.put(nums[i],1);
            }   
            else 
            {  
            
                m.put(nums[i],m.get(nums[i])+1);
            }
        }
        
         
        for (Map.Entry<Integer,Integer> e : m.entrySet())
        {
            if(e.getValue()>nums.length/2)
            {
                return e.getKey();
            }
        }
        
       return -1;
    }
}