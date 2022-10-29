class Solution {
public:
    int earliestFullBloom(vector<int>& plant, vector<int>& grow) {
        
        
        vector<pair<int, int>> v;
    for (auto i = 0; i < plant.size(); ++i)
        v.push_back({grow[i], plant[i]});
    sort(begin(v), end(v));
    int res = 0;
    for (auto it : v)
        res = max(res, it.first) + it.second;
    return res;
    }
};