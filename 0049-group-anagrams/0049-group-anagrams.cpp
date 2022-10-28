class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
   // Time :    O(n k log k)
        
        int i ,j;
        
        unordered_map< string , vector<string>>m;
        vector<vector<string>>ans;
        
        string temp;
        
        for(i=0 ; i<strs.size() ;i++)
        {
            temp = strs[i];
            sort(strs[i].begin() , strs[i].end());
            m[strs[i]].push_back(temp);
        }
        
        unordered_map<string, vector<string>>::iterator it;
        
        for(it=m.begin() ; it!=m.end() ; it++)
        {
            ans.push_back(it->second);
        }
        
        return ans;
       
    }
};