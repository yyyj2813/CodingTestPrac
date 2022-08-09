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
    int maxp=MIN; 
    int maxPathSum(TreeNode* root) {
        return max(maxp, maxPathRecurSum(root));
    } 
    int maxPathRecurSum(TreeNode* root) {
        if(root==nullptr) return 0;
        
        int r = max(0, maxPathRecurSum(root->right));
        int l = max(0, maxPathRecurSum(root->left));
        
        maxp = max(maxp, root->val + r + l);
        
        return root->val + max(r, l);
        
        
    }
};