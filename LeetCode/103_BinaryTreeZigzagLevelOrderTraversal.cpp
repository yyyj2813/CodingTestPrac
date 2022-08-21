#include <deque>
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
    vector<vector<TreeNode*>> tnodes; 
    
    void Traverse(){
        if(tnodes.back().empty()) return; 
        
        vector<TreeNode*> child; 
        for(auto &root:tnodes.back()){
            if(root->left !=nullptr) child.push_back(root->left);
            if(root->right!=nullptr) child.push_back(root->right);
        }
        
        tnodes.push_back(child);
        
        Traverse();
        
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr) return vector<vector<int>>(); 
        
        vector<TreeNode*> st = {root}; 
        tnodes.push_back(st); 
        Traverse(); 
        
        vector<vector<int>> ans;
        bool dir=true; 
        for(auto & levelnodes : tnodes){
            if(levelnodes.empty()) break; 
            vector<int> lans; 
            if(dir) {
                for(auto it=levelnodes.begin(); it!=levelnodes.end(); ++it ) lans.push_back((*it)->val); 
            }
            else {
                for(auto it=levelnodes.rbegin(); it!=levelnodes.rend(); ++it ) lans.push_back((*it)->val); 
            }
            dir=!dir; 
            ans.push_back(lans);
        }
        return ans; 
        
    }
};