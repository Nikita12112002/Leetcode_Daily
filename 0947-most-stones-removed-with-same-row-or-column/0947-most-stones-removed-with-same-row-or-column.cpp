class Solution {
public:
    vector<int> parent;         
    
    int findParent(int node){                   
        if(node==parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    
    bool join(int x, int y){
        x = findParent(x);
        y = findParent(y);
        
        if(x==y) return false;
        
        parent[y]=x;
        return true;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n);
        
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    if(join(i,j)) count++;
                }
            }
        }
        
        return count;
    }
};