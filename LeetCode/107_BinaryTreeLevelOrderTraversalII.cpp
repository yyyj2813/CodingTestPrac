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
#include <queue> 
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans; 
        if(root==nullptr) return ans;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            queue<TreeNode*> nxt_lvl_q;
            vector<int> vec; 
            
            while(!q.empty()){
                TreeNode * pnode = q.front();q.pop(); 
                vec.push_back(pnode->val); 
                
                if(pnode->left!=nullptr) nxt_lvl_q.push(pnode->left);
                if(pnode->right!=nullptr) nxt_lvl_q.push(pnode->right);
                
            }
            while(!nxt_lvl_q.empty()){
                q.push(nxt_lvl_q.front());
                nxt_lvl_q.pop(); 
            }
            
            ans.push_back(vec);
            
        }
        reverse(ans.begin(), ans.end()); 
        
        return ans; 
    }
};