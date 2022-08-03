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
    void levelOrder(vector<vector<int>> &ans, TreeNode* root, int lv){
        if(root==nullptr) return; 
        if(ans.size() <= lv) ans.push_back(vector<int>());
        ans[lv].push_back(root->val);
        levelOrder(ans, root->left, lv+1);
        levelOrder(ans, root->right, lv+1);
    }
    void recurLevelOrder(vector<vector<int>>&res, vector<TreeNode*> & tn){
        if(tn.size() == 0) return;
        res.push_back(vector<int>());
        
        vector<TreeNode*> tnxt; 
        
        for(auto t :tn){
            res.back().push_back(t->val);
            if(t->left!=nullptr) tnxt.push_back(t->left);
            if(t->right!=nullptr) tnxt.push_back(t->right);
        }
        recurLevelOrder(res, tnxt);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans; 
        /* Recursive
        if(root==nullptr) return  vector<vector<int>>();
        vector<TreeNode*> vec={root};
        recurLevelOrder(ans, vec);
        */
        levelOrder(ans,root, 0);
        return ans; 
    }
};