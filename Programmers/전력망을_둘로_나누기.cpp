#include <string>
#include <vector>
#include <cmath> 
using namespace std;
vector<vector<int>> graph; 
const int MAX=987654321;
int min_diff=MAX; 
int total; 

int DFS(vector<bool> &visited, int idx){
    visited[idx] = true; 
    int ret = 1; 
    for(auto nxt: graph[idx]){
        if(visited[nxt]) continue; 
        visited[nxt] = true; 
        int pret = DFS(visited, nxt);//total, total-pret
        min_diff= min(min_diff, abs(total-pret*2)); 
        ret += pret; 
    }
    return ret; 
}

int solution(int n, vector<vector<int>> wires) {
    total = n; 
    
    graph.assign(n,vector<int>());
    for(auto edge: wires){
        graph[edge[0]-1].push_back(edge[1]-1); 
        graph[edge[1]-1].push_back(edge[0]-1); 
    }
    vector<bool> visited(n,false);
    DFS(visited, 0);//0번째가 root라고 가정
    return min_diff;
}