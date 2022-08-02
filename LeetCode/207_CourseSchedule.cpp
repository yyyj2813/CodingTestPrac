#include <queue> 
#include <algorithm> 
class Solution {
public:
    
    bool BFS(vector<vector<int>>& graph, vector<int> &degree, int n ) {
        
        queue<int> q; 
        
        for(int i=0; i<n; ++i){
            if(degree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int now = q.front(); 
            q.pop(); 
            
            for(int x: graph[now]){
                --degree[x];
                if(degree[x]==0) q.push(x);
            }
        }
        
        
        //degree가 0보다 큰 게 아직 존재?
        for(int i=0; i<n; ++i){
            if(degree[i]>0) return false; 
        }
        return true; 
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> degree(numCourses, 0); 
        
        for(auto & v : prerequisites){
            graph[v[1]].push_back(v[0]);
            degree[v[0]]++; 
        }
            
        return BFS(graph, degree, numCourses); 
    }
    
};