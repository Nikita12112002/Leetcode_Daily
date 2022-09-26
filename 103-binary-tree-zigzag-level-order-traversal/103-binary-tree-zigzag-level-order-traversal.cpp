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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        q.push(root);
        int flag=0;
        int index;
        
        if(root==NULL)
            return ans;
        while(!q.empty())
        {
           int sz = q.size();
           
            vector<int>res(sz);
            for(int i=0 ;i<sz ;i++)
            {
                auto node = q.front();
                q.pop();
                if(flag==0)
                    index=i;
                
                else
                    index=sz-1-i;
                
                res[index]=node->val;
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            
            if(flag==0)
                flag=1;
            else
                flag=0;
            ans.push_back(res);
        }
       return ans; 
    }
};