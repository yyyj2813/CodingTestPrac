class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> coord;     
        int h = matrix.size();
        int w = matrix[0].size();
        
        for(int y=0;y<h; ++y){
            for(int x=0; x<w; ++x){
                if(matrix[y][x]==0) {
                    coord.push_back({y,-1});
                    coord.push_back({-1,x});
                }   
            }
        }
        
        for(auto c:coord){
            if(c.first==-1){
                int x=c.second;
                for(int y=0;y<h; ++y) matrix[y][x]=0; 
            }
            else {
                int y =c.first; 
                for(int x=0; x<w;++x) matrix[y][x]=0; 
            }
        }
        
        
    }
};