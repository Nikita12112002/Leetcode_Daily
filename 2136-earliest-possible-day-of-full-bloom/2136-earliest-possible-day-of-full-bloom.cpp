class Solution {
public:
    int earliestFullBloom(vector<int>& plant, vector<int>& grow) {
        
        int start=0;
        vector<pair<int, int>> v;
        
       for (auto i = 0; i < plant.size(); i++)
       {
            v.push_back({grow[i], plant[i]});
       }
        
     sort(v.begin(), v.end(), greater<pair<int,int>>());
        int res = 0;
        for (auto it : v)
        {
            start = start+it.second;
            res = max(res,start+it.first);
        }
    return res;
    }
};