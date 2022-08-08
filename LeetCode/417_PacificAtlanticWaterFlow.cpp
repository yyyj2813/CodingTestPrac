#include <queue>
#include <unordered_map>
class Solution {
public:
    int h, w;
    int dy[4]={0,1,0,-1};
    int dx[4]={1,0,-1,0};
    int InArea(int y, int x){//0: in grid, 1: atlantic ocean, -1: pacific ocean 
        if(y<0||x<0 ) return -1; 
        if(y>=h||x>=w) return 1; 
        return 0; 
    }
    void PushDefault(queue<pair<int,int>> &q, int target){
         vector<vector<int>> ans; 
        
        int basey=0, basex=0;         
        if(target==1) {basey=h-1; basex=w-1; }
        

        for(int y=0; y<h; ++y) {
            q.push({y, basex});
        }
        
        for(int x=0; x<w; ++x) {
            q.push({basey,x});
        }
    }
    
    set<pair<int,int>> BFS(vector<vector<int>>& board, int target){
        
       set<pair<int,int>> s; 
        
        queue<pair<int,int>> q; 
        PushDefault(q, target);
        
        
        while(!q.empty()){
            
            auto now= q.front();
            // cout<<now.first<<','<<now.second<<endl;
            q.pop(); 
            
            int now_height=0; 
            if(InArea(now.first, now.second)==0) now_height=board[now.first][now.second];
            s.insert(now);    

            
            for(int d=0; d<4; ++d){
                int ny=now.first + dy[d];
                int nx=now.second + dx[d];
                
                if(InArea(ny,nx) != 0) continue; //밖

                if(s.find({ny,nx})!=s.end()) continue;//이미 visited

                if(now_height > board[ny][nx]) continue; 
                
                q.push({ny,nx});
            }
            
        }
        return s;
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        h=heights.size();
        w=heights[0].size();
        
        auto s1= BFS(heights, 1);
        auto s2= BFS(heights, -1);
        
        vector<vector<int>>  ans; 
        
        for(auto it1=s1.begin(); it1!= s1.end(); ++it1){
            // cout<<(*it1).first<<","<<(*it1).second; 
            if(s2.find(*it1)==s2.end()) continue; 
            vector<int> v={(*it1).first,(*it1).second};
            ans.push_back(v);
        } 
        
        return ans;    
    }
};