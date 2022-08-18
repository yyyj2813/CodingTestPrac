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
const int MIN=-987654321;
class Solution {
public:
    int max_len; 
    int longestUnivaluePath(TreeNode* root, int val) {
        if(root==nullptr) return 0;
        
        int rval = longestUnivaluePath(root->right, root->val );
        int lval = longestUnivaluePath(root->left, root->val );
        max_len = max(max_len, rval+lval+1);
        
        if(root->val != val ) return 0; 
        return 1 + max(rval, lval); 
        
    }
    int longestUnivaluePath(TreeNode* root) {
        max_len=1; 
        longestUnivaluePath(root, MIN); 
        return max_len-1; 
    }
};