const int MAX=987654321; 
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
        if(y==h-1 && x==w-1) return board[y][x]; 
        
        int &ret=cache[y][x]; 
        if(ret!=-1) return ret; 
        
        ret=MAX; 
        for(int d=0; d<2; ++d){
            int ny = y+dy[d]; 
            int nx = x+dx[d];
            if(!IsValid(ny,nx)) continue; 
            ret = min(board[y][x]+DFS(board,ny,nx), ret);
        }
        
        return ret;         
    }
    
    int minPathSum(vector<vector<int>>& obstacleGrid) {
        h= obstacleGrid.size(); 
        w= obstacleGrid[0].size(); 
        cache.assign(h, vector<int>(w,-1)); 
        
        return DFS(obstacleGrid, 0,0);
        
    }
};