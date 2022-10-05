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
    TreeNode * dfs(TreeNode* root , int val , int depth , int i)
    {
        if(root==NULL)
            return NULL;
        if(i==depth-1)
        {
            TreeNode*left_p = root->left;
            TreeNode*right_p = root->right;
            TreeNode *leftnode = new TreeNode(val);
            TreeNode *rightnode = new TreeNode(val);
            root->left = leftnode;
            root->right = rightnode;
            leftnode->left = left_p;
            rightnode->right = right_p;
            return root;
        }
        
        dfs(root->left,val,depth,i+1);
        dfs(root->right,val,depth,i+1);
        
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(root==NULL)
          return NULL;
        
        TreeNode * node;
        if(depth==1)
        {
            node = new TreeNode(val);
            node->left = root;
            return node;
        }
        
       return dfs(root,val,depth,1);
        
    }
};