// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        // code here
         int parent[n] , key[n] ;
    bool mst[n];
    
     
    
    for(int i=0 ;i<n ;i++)
    {
        key[i]=INT_MAX;
        mst[i]=false;
        parent[i]=-1;
    }
    
    priority_queue<pair<int,int> , vector<pair<int,int>>  ,greater<pair<int,int>>>pq;
    
    key[0]=0;
    parent[0]= -1;
    pq.push({0,0});
    
    while(!pq.empty())
    {
        int par = pq.top().second;
        pq.pop();
    
        mst[par]=true;
        
        for(auto it:adj[par])
        {
            if(mst[it[0]]==false && it[1]<key[it[0]])
            {
                key[it[0]]=it[1];
                parent[it[0]]=par;
                pq.push({key[it[0]],it[0]});
            }
        }
    }
    
    int sum=0;
    for(int i=0 ;i<n ;i++)
    {
        sum = sum + key[i];
    }
    
    return sum;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends