class Solution {
public:
    
    //logic ---> it can be solved using both dfs(cycle detection) and bfs (using toposort).
    
    
    bool dfs(vector<vector<int>>&graph , int src ,vector<int>&vis , vector<int>&pathvis)
    {
        vis[src]=1;
        pathvis[src]=1;
        
        for(auto it:graph[src])
        {
            if(vis[it]==0)
            {
                if(dfs(graph,it,vis,pathvis)==true)
                    return true;
            }
            else
            {
                if(pathvis[it]==1)
                    return true;
            }
                
        }
        pathvis[src]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       
        int n = graph.size();
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        
        for(int i=0 ;i<n;i++)
        {
            if(vis[i]==0)
            {
                dfs(graph,i,vis,pathvis);
            }
        }
        
        vector<int>ans;
        for(int i=0 ; i<n ;i++)
        {
            if(pathvis[i]==0)
                ans.push_back(i);
        }
        
        return ans;
    }
};