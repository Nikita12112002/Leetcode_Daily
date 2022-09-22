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
    int count=0;
void dfs(TreeNode* root , vector<int>&v , unordered_map<int,int>&m)
    {
        if(root==NULL)
            return;
        
        
        v.push_back(root->val);
        m[root->val]++;
    
        
        dfs(root->left,v,m);
        dfs(root->right,v,m);
        
    
         if(root->left ==NULL && root->right==NULL)
        {
            
            int count_odd = 0;
            for (auto it : m)
                if (it.second % 2 == 1)
                    count_odd++;

            if (count_odd <= 1)
                count++;
        }
      
        
      
        v.pop_back();
        m[root->val]--;
        return ;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
       
        if(root==NULL)
            return 0;
        
        unordered_map<int,int>m;
        vector<int>v;
        dfs(root,v,m);
        return count;
        
    }
};