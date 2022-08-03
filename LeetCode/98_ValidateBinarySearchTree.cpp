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
    bool recurValidBST(TreeNode* root, long long llimit, long long rlimit) {
        if(root==nullptr) return true; 
        
        if(!(llimit<root->val &&root->val<rlimit)) return false; 
            
        if(root->left!=nullptr){
            if(root->left->val >= root->val) return false; 
        }
        
        if(root->right!=nullptr){
            if(root->right->val <= root->val) return false; 
        }
        
        return recurValidBST(root->left, llimit, root->val) && recurValidBST(root->right, root->val,rlimit);
        
    }
    bool isValidBST(TreeNode* root) {
        long long MIN = -((long long)1<<32);
        long long MAX = ((long long)1<<32);
        
        return recurValidBST(root,MIN,MAX);
        
    }
};
