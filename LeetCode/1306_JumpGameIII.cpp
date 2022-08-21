#include <queue> 
struct UnionFind{
    vector<int> parent; 
    UnionFind(int n){
        for(int i=0;i<n; ++i)parent.push_back(i); 
    }
    int find(int v){
        if(v==parent[v]) return v;
        return find(parent[v]); 
    }
    void merge(int u, int v ){
        u=find(u);
        v=find(v); 
        if(u==v) return; 
        parent[v]=u; 
    }
    
};
class Solution {
public:
    int n;
    
    bool IsValid(int x){
       if(x<0 || x>=n) return false; 
        return true; 
    }
    
    bool canReach(vector<int>& arr, int start) {
        n = arr.size(); 
        vector<bool> visited(n, false); 
        
        queue<int> q; 
        q.push(start);
        
        while(!q.empty()){
            int now= q.front(); 
            q.pop(); 
            
            if(arr[now]==0) return true;
            
            int nxt1= now+arr[now]; 
            if(IsValid(nxt1) &&!visited[nxt1]) {
                q.push(nxt1); 
                visited[nxt1]=true; 
            }
            
            int nxt2= now-arr[now]; 
            if(IsValid(nxt2) &&!visited[nxt2]) {
                q.push(nxt2); 
                visited[nxt2]=true; 
            }
        }
        
        return false; 
    }
};