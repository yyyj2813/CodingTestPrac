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
    
    vector<int> inorder;
    void TraverseInOrder(TreeNode* root){
        if(root==nullptr)return; 
        TraverseInOrder(root->left);
        preorder.push_back(root->val);
        TraverseInOrder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        TraverseInOrder(root);
        return preorder[k-1];
    }
};