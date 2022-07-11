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
    long long count=0;
    int pathSum(TreeNode* root, int targetSum) {
       
        if(root==NULL)
           return 0;
        
        AllPath(root , targetSum);
        pathSum(root->left , targetSum);
        pathSum(root->right ,targetSum);
        return count;
        
    }
    
    void AllPath(TreeNode* root , long long sum )
    {
        if(root==NULL)
            return;
        
        if(sum-root->val==0)
           count++;
        
        AllPath(root->left , sum-root->val);
        AllPath(root->right , sum-root->val);
       
    }

};