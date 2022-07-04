#include<vector>
#include <queue> 
using namespace std;
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
int h,w; 

bool IsValid(int y, int x){
    if(y<0 || x<0 ||y>=h ||x>=w) return false;
    return true; 
}

int BFS(vector<vector<int> > & maps){
    vector<vector<bool>> visited(h,vector<bool>(w, false));
    queue< pair<int,pair<int,int> > > q;//(길이, 좌표)
    q.push({1,{0,0}});
    visited[0][0]=true; 
    
    while(!q.empty()){
        auto now=q.front(); 
        q.pop(); 
        auto coord=now.second; 
        
        if(coord.first==h-1 && coord.second==w-1) return now.first; 
        
        for(int d=0; d<4; ++d){
            int ny=coord.first+dy[d];
            int nx=coord.second+dx[d];
            if(!IsValid(ny,nx) || visited[ny][nx] ||(maps[ny][nx]==0) ) continue; 

            visited[ny][nx]=true; 
            q.push({now.first + 1,{ny,nx}});
        } 
    }
    return -1; 
}

int solution(vector<vector<int> > maps)
{
    h=maps.size();
    w=maps[0].size();
    
    int answer = BFS(maps);
    return answer;
}