class Solution {
    public String reverseWords(String s) {
        
       int left = 0;
    int right = s.length()-1;
    
    String temp="";
    String ans="";
    int count_spaces=0;
    //Iterate the string and keep on adding to form a word
    //If empty space is encountered then add the current word to the result
        
    while (left <= right) 
    {
       char ch = s.charAt(left);
        if (ch != ' ') 
        {
            temp += ch;
            count_spaces=0;
        } 
        else if (ch == ' ')
        {
             count_spaces++;
            if (ans!="" && count_spaces<=1) 
            {
                ans = temp + " " + ans;
                
            }
            else if(ans==""&&count_spaces<=1)
                ans = temp;
        
            temp = "";
        }
        left++;
    }
    
    //If not empty string then add to the result(Last word is added)
    if (temp!="") {
        if (ans!="") ans = temp + " " + ans;
        else ans = temp;
    }
    
    return ans;    


    }
        
    
}