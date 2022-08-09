/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue> 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr) return "."; 
        string ans=""; 
        queue<TreeNode*> q;
        
        q.push(root);
        while(!q.empty()){
            TreeNode * now= q.front(); 
            q.pop(); 
            
            if(now == nullptr) {
                ans+="./";
                continue;
            }
            else ans +=to_string(now->val)+"/";
            
            q.push(now->left);
            q.push(now->right);
        }
        
        return ans; 
        
    }
    
    void Mapping(TreeNode *root, vector<string> &v, int idx){
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="./" ||data==""||data==".") return nullptr; 
        
        //parsing
        istringstream ss(data);
        string buf;
        
        vector<string> v;    
        
        while(getline(ss, buf, '/')){
            v.push_back(buf);            
        }
        
        
        queue <TreeNode *> q;
        TreeNode *root =new TreeNode( stoi(v[0]) );  
        q.push(root);
        
        int idx=1; 
        
        while(!q.empty()){
            auto now = q.front(); q.pop(); 
                
            TreeNode *left = nullptr; 
            if(v[idx].compare(".")!=0) left= new TreeNode(stoi(v[idx])); ++idx; 
            
            TreeNode *right = nullptr; 
            if(v[idx].compare(".")!=0) right= new TreeNode(stoi(v[idx])); ++idx;
            
            now->left = left;
            now->right = right;
            
            if(left!=nullptr) q.push(left);
            if(right!=nullptr) q.push(right);

        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));