#include <string>
#include <vector>
using namespace std;
int n; 
const int MIN=-987654321;

int Explore(vector<vector<int>> &dungeons, vector<bool> & visited, int fuel){
    
    int ret = 0;
    
    for(int i=0; i<n; ++i){
        if( visited[i] || (dungeons[i][0] > fuel) ) continue; 
        //i를 방문 
        visited[i] = true; 
        ret = max(ret, 1 + Explore(dungeons, visited, fuel-dungeons[i][1]) );
        visited[i] = false; 
    }
    
    return ret;    
    
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer;
    
    n=dungeons.size(); 
    vector<bool> visited(n, false);
    
    answer= Explore(dungeons, visited, k);
    
    return answer;
}