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
    
    void countNodes(TreeNode* root, int m)
    {
        if(root==NULL)
            return;
        if(root->val>=m)
        {
            count++;
            m = max(m,root->val);
        }
        
        countNodes(root->left,m);
        countNodes(root->right,m);
        
       }
    int goodNodes(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        if(root->left==NULL && root->right==NULL)
            return 1;
        
        countNodes(root,INT_MIN);
        return count;
            
    }
};