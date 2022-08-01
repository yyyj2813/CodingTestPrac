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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; 
        levelOrder(ans,root, 0);
        return ans; 
    }
};