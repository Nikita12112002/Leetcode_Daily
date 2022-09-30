/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void markPar(TreeNode* root , TreeNode* target,map<TreeNode*,TreeNode*>&m)
    {
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            
            if(node->left)
            {
                q.push(node->left);
                m[node->left]=node;
            }
            
            if(node->right)
            {
                q.push(node->right);
                m[node->right]=node;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       
        map<TreeNode*,TreeNode*>m;
        markPar(root,target,m);
        vector<int>ans;
        map<TreeNode*,bool>visited;
        
        queue<TreeNode*>q;
        q.push(target);
        
        visited[target]=true;
        
        int count=0;
        while(!q.empty())
        {
            
            if(count==k)
                break;
            else
                count++;
            
            int sz = q.size();
            
            for(int i=0 ;i<sz ;i++)
            {
                auto node = q.front();
                q.pop();
                
                if(node->left && !visited[node->left])
                {
                    visited[node->left]=true;
                    q.push(node->left);
                }
                
                if(node->right && !visited[node->right])
                {
                    visited[node->right]=true;
                    q.push(node->right);
                }
                    
                if(m[node] && !visited[m[node]])
                {
                    visited[m[node]]=true;
                    q.push(m[node]);
                }
            }
        }
      
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};