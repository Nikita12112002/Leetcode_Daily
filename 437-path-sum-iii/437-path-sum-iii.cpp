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
    
    unordered_map<int,int>m;
    long long count=0;
    int pathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL)
            return 0;
        
        path(root , targetSum,0);
        
        return count;
        
    }
    
    void path(TreeNode* root ,long long target , long long sum)
    {
        if(root==NULL)
            return;
        
         sum = sum+root->val;
        
        if(sum==target)
            count++;
        
        if(m.find(sum-target)!=m.end())
            count = count + m[sum-target];
        
        m[sum]++;
        
        path(root->left , target , sum);
        path(root->right , target , sum);
        
        m[sum]--;
    }
    
        
};