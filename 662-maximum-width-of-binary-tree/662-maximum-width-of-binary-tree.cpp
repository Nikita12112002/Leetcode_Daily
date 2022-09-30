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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        long long maxi=0;
        
        while(!q.empty())
        {
            auto node = q.front().first;
            long long mini = q.front().second;
             
            long long sz=q.size();
            long long first , last;
            
            for(int i=0 ;i<sz ;i++)
            {
                auto node = q.front().first;
                long long index = q.front().second-mini;
                q.pop();
                
                if(i==0)
                     first=index;
                if(i==sz-1)
                     last = index;
                
                if(node->left)
                    q.push({node->left,index*2+1});
                
                if(node->right)
                    q.push({node->right,index*2+2});
            }
            
            maxi=max(maxi,last-first+1);
        }
        return maxi;
    }
};