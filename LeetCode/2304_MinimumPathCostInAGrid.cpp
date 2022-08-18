const int MAX=987654321; 
class Solution {
public:
    vector<vector<int>> cache; 
    int h, w; 
    int MinMove(vector<vector<int>>& grid, vector<vector<int>>& cost, int x, int y){
        if(x==h-1) return grid[x][y];//끝 
        
        int &ret= cache[x][y];
        if(ret!=-1) return ret; 
        
        int now_cost=grid[x][y]; 
        
        int nx=x+1;
        ret=MAX; 
        for(int ny=0; ny<w; ++ny){
            ret=min(ret, now_cost+cost[now_cost][ny] + MinMove(grid, cost, nx, ny));
        }
        return ret; 
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        h=grid.size(); 
        w=grid[0].size(); 
        cache.assign(h,vector<int>(w,-1)); 
        
        int ret=MAX; 
        for(int ny=0; ny<w; ++ny){
            ret=min(ret, MinMove(grid, moveCost,0,ny)); 
        }
        return ret; 
    }
};