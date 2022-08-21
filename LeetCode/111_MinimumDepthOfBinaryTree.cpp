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
const int MAX=987654321; 
class Solution {
public:
    int min_cur; 
    void minDepth(TreeNode* root, int d) {
        if(root==nullptr) return; 
        if( root->right==nullptr && root->left==nullptr) {
            min_cur=min(min_cur, d); 
            return; 
        }
        
        if(d>min_cur) return;  
        
        minDepth(root->right, d+1); 
        minDepth(root->left, d+1); 
    }
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0; 
   
        min_cur=MAX;      
        minDepth(root,1);
        return min_cur; 
    }
};