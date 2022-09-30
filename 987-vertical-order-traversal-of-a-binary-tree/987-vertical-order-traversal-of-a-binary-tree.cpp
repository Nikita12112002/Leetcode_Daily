/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        map<int,map<int,multiset<int>>>m;
        
        while(!q.empty()){
                auto node = q.front();
                q.pop();
                
                auto p = node.first;
                int x = node.second.first;
                int y = node.second.second;
                
                m[x][y].insert(p->val);
                
                if(p->left)
                    q.push({p->left,{x-1,y+1}});
                if(p->right)
                    q.push({p->right,{x+1,y+1}});
        }
        
        vector<vector<int>>res;
        
        for(auto it:m)
        {
            vector<int>col;
            for(auto q:it.second)
            {
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            
            res.push_back(col);
        }
        
        return res;
    }
};