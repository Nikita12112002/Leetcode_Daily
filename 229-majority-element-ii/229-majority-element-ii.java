class Solution {
    public List<Integer> majorityElement(int[] nums) {
        
       HashMap<Integer,Integer>m = new HashMap<>();
        ArrayList<Integer>list = new ArrayList<>();
        
        for(int i=0 ; i<nums.length ;i++)
        {
            if(!m.containsKey(nums[i]))
                 m.put(nums[i],1);
            else
                m.put(nums[i],m.get(nums[i])+1);
        }
        
       for(Map.Entry<Integer,Integer>e : m.entrySet())
       {
           if(e.getValue()>nums.length/3)
               
               list.add(e.getKey());
               
       }
            
       return list; 
    }
}