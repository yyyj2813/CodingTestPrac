const int VISITED=-2; 
class Solution {
public:
    int h, w; 
    int sy,sx; 
    int ey,ex; 
    int to_walk; 
    int dy[4]={1,0,-1,0};
    int dx[4]={0,1,0,-1};
    
    bool IsValid(int y, int x){
        if(y<0 || y>=h||x<0||x>=w) return false; 
        return true; 
    }
    int DFS(vector<vector<int>>& board, int y, int x, int cnt){
        if(y==ey && x==ex && cnt==to_walk) return 1; 
        if(cnt==to_walk) return 0; 
        
        int tmp = board[y][x]; 
        board[y][x] = -2; 
        
        int ret=0; 
        for(int d=0;d<4; ++d){
            int ny=y+dy[d];
            int nx=x+dx[d];
            if(!IsValid(ny,nx) || board[ny][nx]<0) continue;
            ret+=DFS(board, ny, nx, cnt+1);
        }
        board[y][x] = tmp; 
        return ret; 
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        h=grid.size(); 
        w=grid[0].size();
        to_walk=0; 
        
        for(int y=0;y<h; ++y){
             for(int x=0;x<w; ++x){
                if(grid[y][x] != -1) ++to_walk; 
                if(grid[y][x] == 1) {sy=y; sx=x;}
                if(grid[y][x] == 2) {ey=y; ex=x;} 
            }   
        }
        return DFS(grid, sy, sx, 1); 
    }
};