
int n =0; 
class Solution {
public:
    void RotateOne(vector<vector<int>>& matrix, int y, int x){

        int cnt=0; 
        
        int bf_val=matrix[y][x]; 
        
        while(cnt<4){
            int ny=x; 
            int nx=n-1-y;
            
            int tmp = matrix[ny][nx];
            matrix[ny][nx] = bf_val;
            bf_val= tmp; 
            
            y=ny; x=nx; 
            ++cnt; 
        }
        return; 
    }
    
    void RotateQuarter(vector<vector<int>>& matrix,int y,int x){
        for(int i=0;i<y; ++i){
            for(int j=0;j<x; ++j){
                RotateOne(matrix, i,j);
            }
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        n=matrix.size(); 
        int y= n/2; 
        int x= (n%2==0)? n/2: n/2+1 ; 
        RotateQuarter(matrix,y,x);
    }
};