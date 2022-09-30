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
    
    TreeNode* build(vector<int>&in , int ins , int ine , vector<int>&post , int post_s , int post_e , unordered_map<int,int>&m)
    {
        if(ins>ine || post_s > post_e)
            return NULL;
        
        TreeNode * root = new TreeNode(post[post_e]);
        
        int inroot = m[root->val];
        
        int numsLeft = inroot-ins;
        
        root->left = build(in,ins,inroot-1,post,post_s , post_s+numsLeft-1,m);
        root->right = build(in,inroot+1,ine,post, post_s+numsLeft ,post_e-1,m);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        
        unordered_map<int,int>m;
        
        for(int i=0 ; i<in.size();i++)
        {
            m[in[i]]=i;
        }
        
        TreeNode* root = build(in,0,in.size()-1 , post , 0 , post.size()-1 ,m);
        
        return root;
        
    }
};