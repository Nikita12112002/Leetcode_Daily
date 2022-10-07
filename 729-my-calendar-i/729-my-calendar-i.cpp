class MyCalendar {
public:
    vector<pair<int,int>>temp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
       
       
        
        for(auto it:temp)
        {
            
            if(it.second >start && it.first<end)
            {
                return false;
            }
        
        }
       
     temp.push_back({start,end});
        
     return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */