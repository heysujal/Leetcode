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
    
     bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(!p and !q)
            return true;
        if(!p or !q)
                  return false;
        
       
        bool op1 = isSameTree(p->left, q->right);
        bool op2 = isSameTree(p->right, q->left);
         
        return op1 and op2 and p->val==q->val;
        
        
        
        
    }
    
    bool isSymmetric(TreeNode* root) {
        
        
        if(!root )
            return false;
       
        return isSameTree(root->left , root->right);
      
    }
};