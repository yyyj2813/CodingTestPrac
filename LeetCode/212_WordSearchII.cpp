
int getIdx(char c){
    return c-'a';
}

class Trie{
    public: 
    Trie * children[26];
    int terminal; 
    Trie(): terminal(-1){
        memset(children, 0, sizeof(children));
    }
    
    int search(char *key){
        if( *key == 0){
            return terminal; 
        }
        int nxt = getIdx(*key);
        if(children[nxt] == NULL) return -1;
        return children[nxt]->search(key+1);
    }
    
    void insert(char * key, int arr_idx){
        if(*key == 0) {
            terminal = arr_idx; 
            return;
        }
        int nxt = getIdx(*key);
        if(children[nxt] == NULL){
            children[nxt] = new Trie(); 
        }
        return children[nxt]->insert(key+1, arr_idx);
    }
};


class Solution {
public:
    Trie trie;
    int h, w; 
    int dy[4]={0,1,0,-1};
    int dx[4]={1,0,-1,0};
    set<int> appeared_idxs;
    
    bool IsValid(int y, int x){
        if(y<0 || y>=h || x<0 || x>=w ) return false;
        return true;
    }
    
    void DFS(vector<vector<char>>& board, Trie * trie, int y, int x ){
        
        if(trie==NULL) return; 

        int idx = getIdx(board[y][x]);
        Trie * nxt_trie = trie->children[idx];
        
        if(nxt_trie == NULL) return;
        if(nxt_trie->terminal != -1) appeared_idxs.insert(nxt_trie->terminal);

        
        char tmp = board[y][x];
        board[y][x]='.';
        
        
        for(int d=0; d<4; ++d){
            int ny = y + dy[d];
            int nx = x + dx[d];
            
            if(!IsValid(ny,nx) || board[ny][nx]=='.' ) continue; 

            DFS(board, nxt_trie, ny, nx);      
        }
        
        board[y][x]=tmp;
        
        return; 
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        h = board.size();
        w = board[0].size();
        
        for(int i=0; i<words.size();++i){
            trie.insert(&words[i][0], i); 
            // cout<<"\t"<<trie.search(&words[i][0])<<endl; 
        }
        for(int y=0;y<h; ++y){
            for(int x=0; x<w; ++x) DFS(board, &trie, y,x);
        }
        vector<string> ans; 
        
        for(auto it= appeared_idxs.begin(); it!=appeared_idxs.end(); ++it){
            ans.push_back(words[*it]);
        }       
        return ans; 
    }
};