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
    vector<vector<TreeNode*>> levels; 
    void Traverse(){
        if(levels.back().empty()) return; 
        
        vector<TreeNode*> nxt_lvl;
        
        for(auto tnode:levels.back()){
            if(tnode->left != nullptr) nxt_lvl.push_back(tnode->left);
            if(tnode->right != nullptr) nxt_lvl.push_back(tnode->right);
        }
        levels.push_back(nxt_lvl);
        Traverse();    
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == nullptr) return vector<double>();
        
        vector<TreeNode*> l1={root}; 
        levels.push_back(l1); 
        Traverse();
        
        vector<double> ans; 
        
        for(auto & level : levels){
            if(level.empty()) break; 
            double sum=0; 
            double cnt=0; 
            for(auto &node:level){
                sum += node->val; 
                ++cnt; 
            }
            ans.push_back(sum/cnt); 
        }
        
        return ans; 
    }
};