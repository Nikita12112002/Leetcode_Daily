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
    
    TreeNode * build(vector<int>&pre , int ps , int pe  , vector<int>&in , int ins , int ine , unordered_map<int,int>&m)
    {
        if(ps>pe || ins>ine)
            return NULL;
        TreeNode * root = new TreeNode(pre[ps]);
        
        int inroot = m[root->val];
        
        int numsLeft = inroot-ins;
        
        root->left = build(pre, ps+1, pe+numsLeft , in , ins , inroot-1 ,m);
        root->right = build(pre , ps+numsLeft+1 , pe , in , inroot+1 , ine,m );
        
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        
       
        int n = in.size();
        unordered_map<int,int>m;
        
        for(int i=0 ;i<n;i++)
        {
            m[in[i]]=i;
        }
        
        TreeNode* root = build(pre,0,pre.size()-1 , in , 0 , in.size()-1 ,m);
        return root;
        
    }
};