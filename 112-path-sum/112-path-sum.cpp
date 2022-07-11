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
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL)
            return false;
       
        if(root->left==NULL && root->right==NULL) // done becoz it is mentioned in the question that we need to find the path from leaf to node ...if we got the sone in between before reaching to the leaf node then that path will not be considered
        {
        if(targetSum-root->val==0)
            return true;
        }
     return hasPathSum(root->left,targetSum-root->val)||
        hasPathSum(root->right,targetSum-root->val);
        
       
        
    }
};