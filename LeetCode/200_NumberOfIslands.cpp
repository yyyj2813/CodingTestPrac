class Solution {
public:
    int h,w; 
    vector<vector<bool>> visited; 
    int dy[4]={0,0,1,-1};
    int dx[4]={1,-1,0,0};
    
    bool IsValid(int y, int x){
        if(y<0 || x<0 || y>=h ||x>=w) return false; 
        return true;
    }
    
    void DFS(vector<vector<char>>& grid,int y, int x){
        visited[y][x]=true;
        for(int d=0; d<4; ++d){
            int ny=y+dy[d];
            int nx=x+dx[d];
            if(!IsValid(ny,nx) || visited[ny][nx] || grid[ny][nx]=='0') continue; 
            DFS(grid, ny,nx);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        h = grid.size();
        w = grid[0].size();
        visited.assign(h, vector<bool>(w,false));
        
        
        int cnt=0; 
        for(int y=0; y<h; ++y){
            for(int x=0; x<w; ++x){
                if(visited[y][x]||grid[y][x]=='0') continue; 
                DFS(grid,y,x);
                ++cnt; 
            }
        }
        return cnt; 
    }
};