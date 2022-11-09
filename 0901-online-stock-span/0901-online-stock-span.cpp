class StockSpanner {
public:
     stack<pair<int,int>>st;
    int i=0,k;
    StockSpanner() {
        
    }
    
    int next(int price) {
       
       
          while(!st.empty() && st.top().first<=price)
            {
                st.pop();
            }
        i++;
            
               if(!st.empty())
                {
                    k=i-st.top().second;
                }
        else
            k=i;
            
            st.push({price,i});
        
        return k;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */