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
#include <unordered_map> 
class Solution {
public:
    vector<unordered_map<TreeNode*, int>> vmap;
    
    int MaxRob(TreeNode* root, bool can_rob=true){
        if(root==nullptr) return 0; 
        if(root->left == nullptr && root->right == nullptr) return can_rob? root->val:0;
        
        int idx=can_rob?1:0; 
        if(vmap[idx].find(root)!=vmap[idx].end()) return vmap[idx][root]; 
        
        int ret=0; 
        
        if(can_rob) ret = root->val+ MaxRob(root->left, false) + MaxRob(root->right,false);
        ret= max(ret, MaxRob(root->left, true) + MaxRob(root->right,true));
        
        vmap[idx][root]=ret; 
        return ret; 
        
    }
    
    int rob(TreeNode* root) { 
        vmap.assign(2, unordered_map<TreeNode*, int>());
        return MaxRob(root);
    }
};