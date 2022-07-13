/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
//         if(cloned==NULL)
//             return NULL;
        
//         if(cloned->val == target->val)
//            ans= cloned;
        
//         getTargetCopy(original,cloned->left,target);
//         getTargetCopy(original,cloned->right,target);
        
//         return ans;
 
// folllow up: if there are duplicate values you need to check addresses , at that time above code will not work
        if(original==NULL)
            return NULL;
        
        if(original==target)
            return cloned;
        
      TreeNode* left = getTargetCopy(original->left,cloned->left,target);
       TreeNode* right = getTargetCopy(original->right,cloned->right,target);
        
        if(left==NULL)
            return right;
        
        return left;
    }
};