class Solution {
public:
    vector<vector<int>>cache; 
    int dy[2]={0,1}; 
    int dx[2]={1,0}; 
    int h, w; 
  
    bool IsValid(int y , int x){
        if(y<0 || x<0|| y>=h || x>=w) return false; 
        return true; 
    }
    
    int DFS(vector<vector<int>>& board, int y, int x){
        if(y==h-1 && x==w-1) return 1; 
        
        int &ret=cache[y][x]; 
        if(ret!=-1) return ret; 
        
        board[y][x]=-1;
        ret=0; 
        
        for(int d=0; d<2; ++d){
            int ny = y+dy[d]; 
            int nx = x+dx[d];
            if(!IsValid(ny,nx)|| board[ny][nx]!=0) continue; 
            ret+= DFS(board,ny,nx);
        }
        board[y][x]=0;
        
        return ret;         
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        h= obstacleGrid.size(); 
        w= obstacleGrid[0].size(); 
        cache.assign(h, vector<int>(w,-1)); 
        if(obstacleGrid[0][0]==1) return 0; 
        
        return DFS(obstacleGrid, 0,0);
        
    }
};