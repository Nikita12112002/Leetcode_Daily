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
    int minDepth(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        int left = minDepth(root->right);
        int right = minDepth(root->left);
        
        if(left==0 || right==0) // this is to handle skewed tree. check sample ex -2
        {
            return 1+max(left,right);
        }
        return 1+min(left,right);
        
    }
};