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
    TreeNode * sr; 
    unordered_map<TreeNode *,TreeNode *> m; //0: 없음, 1: true, 2: false; 
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr && subRoot ==nullptr) return true; 
        else if (root==nullptr || subRoot==nullptr) return false;
        
        bool ret=false;
        
        ret= ret || isSubtree(root->right, subRoot);
        ret= ret || isSubtree(root->left, subRoot);
        
        ret= ret || recurSubtree(root,subRoot);
        return ret;
    }
    bool recurSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr && subRoot==nullptr ) return true; 
        else if (root==nullptr || subRoot==nullptr) return false; 
    
        bool ret=false; 
        
        if(root->val==subRoot->val){
            ret = recurSubtree(root->left, subRoot->left) && recurSubtree(root->right, subRoot->right);
        }
        
        return ret; 
        
    }
};