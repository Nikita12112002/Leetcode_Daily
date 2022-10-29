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
//     TreeNode* markParents(TreeNode* root , int start ,unordered_map<TreeNode*,TreeNode*>m , queue<TreeNode*>q)
//     {
//         q.push(root);
//         TreeNode* res;
//         while(!q.empty())
//         {
//             auto node = q.front();
            
//             if(node->val==start)
//                 res=node;
                
//             q.pop();
            
//             if(node->left)
//             {
//                 q.push(node->left);
//                 m[node->left]=node;
//             }
//             if(node->right)
//             {
//                 q.push(node->right);
//                 m[node->right]=node;
//             }
//         }
//         return res;
//     }
      TreeNode* markParents(TreeNode* root , int start , unordered_map<TreeNode*,TreeNode*>&par)
  {
      queue<TreeNode*>q;
      q.push(root);
      TreeNode* res;
      
      while(!q.empty())
      {
          
          auto node = q.front();
          q.pop();
          
          if(node->val==start)
            res=node;
            
          if(node->left)
          {
              q.push(node->left);
              par[node->left]=node;
          }
          
          if(node->right)
          {
              q.push(node->right);
              par[node->right]=node;
          }
      }
     return res; 
  }
    int amountOfTime(TreeNode* root, int start) {
        
//         queue<TreeNode*>q;
//         unordered_map<TreeNode*,TreeNode*>m1;
//         TreeNode* res = markParents(root,start,m1,q);
        
//         queue<TreeNode*>q2;
//         unordered_map<TreeNode*, bool>m2;
//         int time=0,flag=0;
//         q2.push(res);
//         m2[res]=true;
//         while(!q2.empty())
//         {
//             int sz = q2.size();
//             flag=0;
            
//             for(int i=0 ;i<sz ;i++)
//             {
//             auto node = q2.front();
//             q2.pop();
            
//             if(node->left && m2[node->left]==false)
//             {
//                 flag=1;
//                 q2.push(node->left);
//                 m2[node->left]=true;
//             }
            
//             if(node->right && m2[node->right]==false)
//             {
//                 flag=1;
//                 q2.push(node->right);
//                 m2[node->right]=true;
//             }
            
//             if(m1[node] && m2[m1[node]]==false)
//             {
//                 q2.push(m1[node]);
//                 m2[m1[node]]=true;
                
//             }
//             } 
//             if(flag==1)
//                 time++;
//         }
//         return time;
        
          unordered_map<TreeNode*,TreeNode*>par;
      TreeNode* target = markParents(root,start,par);
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int time=0;
        
        while(!q.empty())
        {
            
            int size=q.size();
            int flag=0;
            
            for(int i=0 ;i<size ;i++)
            {
                auto node = q.front();
                q.pop();
                
                if(node->left && !visited[node->left])
                {
                    flag=1;
                    q.push(node->left);
                    visited[node->left]=true;
                }
                
                if(node->right && !visited[node->right])
                {
                    flag=1;
                    q.push(node->right);
                    visited[node->right]=true;
                }
                
                if(par[node] && !visited[par[node]])
                {
                    flag=1;
                    q.push(par[node]);
                    visited[par[node]]=true;
                }
                
            }
            
            if(flag==1)
            time++;
            
        }
        return time;
    }
};