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
    
    TreeNode* build(vector<int>&pre , int &i , int max)
    {
        if(i==pre.size() || pre[i]>max)
            return NULL;
        
        TreeNode * root = new TreeNode(pre[i++]);
        
        root->left = build(pre,i,root->val);
        root->right = build(pre,i,max);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        
        int i=0;
        return build(pre,i,INT_MAX);
    }
};