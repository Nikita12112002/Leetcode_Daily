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
    vector<int> findMode(TreeNode* root) {
        
         vector<int>res;
           if(root==NULL)
               return res;
        
        unordered_map<int,int>m;
        vector<int>ans;
       
        
     
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0 ;i<sz ;i++)
            {
              auto node = q.front();
              q.pop();
                
              if(node->left!=NULL)
                  q.push(node->left);
            
               if(node->right!=NULL)
                   q.push(node->right);
            
             ans.push_back(node->val);
            }
        }
        
            for(int i=0 ;i<ans.size();i++)
            {
                m[ans[i]]++;
            }
            
            int maxi=0;
            for(auto it:m)
            {
                if(it.second>=maxi)
                {
                    maxi=it.second;
                    
                }
            }
            
        for(auto it:m)
        {
            if(it.second>=maxi)
            {
                res.push_back(it.first);
            }
        }
            return res;
    }
};