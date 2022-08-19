class Solution {
public:
    int edgeScore(vector<int>& edges) {
        
        unordered_map<long long,long long>m;
        
        for(int i=0;i<edges.size();i++)
        {
            m[edges[i]]=m[edges[i]]+i;
        }
        
        int maxi=INT_MIN;
        int ans=0;
        for(auto it:m)
        {
            if(it.second>maxi)
            {
                maxi=it.second;
                ans=it.first;
            }
            else if(it.second==maxi)
            {
                if(it.first<ans)
                    ans=it.first;
            }
        }
        
       
        return ans;
    }
};