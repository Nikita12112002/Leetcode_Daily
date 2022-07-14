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
   int sum=0;
    void add(TreeNode* root ,int cur)
    {
        if(root==NULL)
            return ;
        
         cur=cur*10+root->val;
        
         if(root->left==NULL && root->right==NULL)
            sum = sum+cur;
        
         add(root->left,cur);
        
         add(root->right,cur);
       
        
    }
    int sumNumbers(TreeNode* root) {
        
         
        add(root,0);
        return sum;
        
    }
};