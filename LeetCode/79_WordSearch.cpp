class Solution {
public:
    int h,w; 
    string gword;
    int dy[4]={0,1,0,-1};
    int dx[4]={1,0,-1,0};
    bool IsValid(int y, int x){
        if(y<0||y>=h||x<0||x>=w) return false; 
        return true;
    }
    bool DP(vector<vector<char>>& visited, int idx,int y, int x ){
        
        if(visited[y][x] != gword[idx]) return false;
        if(idx == gword.size()-1) return true; 
        
        char now = visited[y][x];
        //cout<<y<<','<<x<<":"<<now<<endl;

        visited[y][x] = 0; 
        
        bool ret = false; 
        for(int d=0; d<4; ++d){
            int ny=y+dy[d];
            int nx=x+dx[d];
            if(!IsValid(ny,nx) || visited[ny][nx]==0) continue; 
            ret= ret||DP(visited, idx+1, ny, nx);
        }
        
        visited[y][x]=now; 
        
        
        return ret; 
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        gword=word; 
        h=board.size(); 
        w=board[0].size(); 
        
        vector<vector<char>> visited(board);
        for(int y=0; y<h; ++y){
            for(int x=0; x<w; ++x){
                bool ret = DP(visited, 0, y,x);
                if(ret) return true; 
            }    
        }
        return false; 
        
    }
};