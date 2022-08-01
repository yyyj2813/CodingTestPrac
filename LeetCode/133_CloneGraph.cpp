/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
#include <map>
class Solution {
public:
    map<Node *, Node *> m; 
    
    Node* cloneGraph (Node* node) {
        if(node==nullptr) return nullptr;
        
        if(m.find(node)!=m.end()) return m[node];    
        
        Node *n =new Node(); 
        n->val = node->val; 
        m[node] = n; 
        
        for(Node * cn: node->neighbors){
            Node * cpycn = cloneGraph(cn);
            n->neighbors.push_back(cpycn);
        }
        return n; 
    }
};