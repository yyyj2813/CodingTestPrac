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
    int sumNumbers(TreeNode* root, int val=0) {
        if(root==nullptr) return -1; 

        int d = root->val; 
        int nxt_val=val*10+ d; 
        
        if(root->right ==nullptr && root->left==nullptr) return nxt_val; 

        int r = sumNumbers(root->right, nxt_val); 
        int l = sumNumbers(root->left, nxt_val); 
        
        int ret=0; 
        if(r!=-1) ret+=r; 
        if(l!=-1) ret+=l;
        
        return ret; 
        
    }
};