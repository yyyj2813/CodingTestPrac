const int MIN=-987654321; 
class Solution {
public:
    int dy[4]={0,1,0,-1};
    int dx[4]={1,0,-1,0};
    int h, w; 
    bool IsValid(int y, int x){
        if(y<0||y>=h || x<0 || x>=w) return false; 
        return true; 
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int y=0,x=0;         
        int dir=0; 
        vector<int> ans; 
        
        h=matrix.size(); 
        w=matrix[0].size(); 
        
        while(true){
            if( !IsValid(y, x) || matrix[y][x] == MIN) break; 
            ans.push_back(matrix[y][x]);
            matrix[y][x]=MIN; 
            
            int tmpy=y+dy[dir];
            int tmpx=x+dx[dir];
            
            if( !IsValid(tmpy, tmpx) || matrix[tmpy][tmpx]==MIN) {
                dir=(dir+1)%4;
                y=y+dy[dir]; 
                x=x+dx[dir];
            }
            else {
                y=tmpy; x=tmpx;     
            }
        }
        
        return ans; 
        
    }
};