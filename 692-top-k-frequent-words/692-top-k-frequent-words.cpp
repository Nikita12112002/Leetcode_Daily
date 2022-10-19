class comp{
    public:
    bool operator()(const pair<int,string> &a, const pair<int,string> &b) const{
        
        if(a.first==b.first)
            return a.second<b.second;
        return a.first>b.first;
    }
};

class Solution {
public:
      
 
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int>m;
        
        for(int i=0 ;i<words.size();i++)
        {
            m[words[i]]++;
        }
        
         priority_queue<pair<int, string>, vector<pair<int, string>>, comp>pq; 
        
        
        for(auto it:m)
        {
            
             pq.push({it.second, it.first});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        
        vector<string>v(k);
        
        int count=k-1;
        
        while(pq.size()>0)
        {
            v[count--]=pq.top().second;
            pq.pop();
        }
        
        return v;
    }
};