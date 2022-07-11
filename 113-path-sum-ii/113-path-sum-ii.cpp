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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>>res;
        vector<int>ans;
        if(root==NULL)
            return res;
        AllPath(root , targetSum , res , ans);
        return res;
        
    }
    
    void AllPath(TreeNode* root , int sum , vector<vector<int>>&res,vector<int>ans)
    {
        if(root==NULL)
            return;
        
        ans.push_back(root->val);
        
        if(root->left==NULL && root->right==NULL)
        {
            if(sum-root->val==0)
            {
                res.push_back(ans);
            
            }
        }
        
        AllPath(root->left , sum-root->val , res ,ans);
        AllPath(root->right , sum-root->val , res ,ans);
        
        ans.pop_back();
       
    }
};