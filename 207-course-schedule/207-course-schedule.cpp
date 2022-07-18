class Solution {
public:
    
    void topoSort(vector<int>adj[] , vector<int>&vis , int node , stack<int>&st)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(vis[it]==0)
                topoSort(adj,vis,it,st);
        }
        
        st.push(node);
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        
        int n = numCourses;
         vector<int>adj[n];
        vector<int>vis(n,0);
        
        for(auto it:pre)
        {
            adj[it[1]].push_back(it[0]);
        }
        stack<int>st;
        
        for(int i=0 ;i<n ;i++)
        {
            if(vis[i]==0)
            {
                topoSort(adj,vis,i,st);
            }
        }
        
        vector<int> ans(numCourses,-1);
        int index=0;
        while(!st.empty())
        {
            int t=st.top();
            st.pop();
            ans[t]=index;
            index++;
        }
        
        for(int i=0 ;i<n ;i++)
        {
            for(auto it:adj[i])
            {
                if(ans[i]>=ans[it])
                    return false;
            }
        }
        return true;
    }
};

