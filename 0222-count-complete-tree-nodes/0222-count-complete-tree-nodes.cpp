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
    
    int findleftheight(TreeNode* root)
    {
        int count=0;
        while(root!=NULL)
        {
            count++;
            root=root->left;
        }
        return count;
    }
    int findrightheight(TreeNode* root)
    {
        int count=0;
        while(root!=NULL)
        {
            count++;
            root=root->right;
        }
        return count;
    }
    int countNodes(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        int lh = findleftheight(root);
        int rh = findrightheight(root);
        
        if(lh==rh)
            return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};