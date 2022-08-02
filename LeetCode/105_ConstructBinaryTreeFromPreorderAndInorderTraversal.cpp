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
#include <algorithm> 
class Solution {
public:
    
    TreeNode * recur(vector<int>::iterator pre_sit,
                     vector<int>::iterator pre_eit,
                     vector<int>::iterator in_sit, 
                     vector<int>::iterator in_eit) {
        
        if(pre_sit==pre_eit ||in_sit==in_eit) return nullptr; 
        
        TreeNode * root = new TreeNode( (*pre_sit));
        
        if(pre_eit-pre_sit==1) return root; 
        auto it = find(in_sit, in_eit, (*pre_sit));
        
        int l_size = it - in_sit;
        
        TreeNode * l= recur(pre_sit+1, pre_sit+l_size+1, in_sit, it);
        TreeNode * r = recur(pre_sit+l_size+1, pre_eit, it+1, in_eit);
 
        root->left = l; 
        root->right = r;
        return root; 
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return recur( preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};