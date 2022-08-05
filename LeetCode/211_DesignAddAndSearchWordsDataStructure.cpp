class WordDictionary {
public:
    
    WordDictionary * alpha[26];
    bool terminal; 
    
    WordDictionary():terminal(false) {
        memset(alpha, 0, sizeof(alpha));    
    }
    int toIdx(char c){
        if(c=='.') return -1; 
        return c-'a';
    }
    
    void addWord(string word) {
        return addWord(&word[0]);
    }
    
    bool search(string word) {
        return search(&word[0]);
    }
    
    void addWord(char *key) {
        if(*key==0) {
            terminal=true; 
            return;
        }
        
        int nxt=toIdx(*key);
        
        if(alpha[nxt]==NULL) alpha[nxt]=new WordDictionary();
        
        alpha[nxt]->addWord(key+1); 
    }
    
    bool search(char *key) {
        if(*key==0 ) return terminal;
        int nxt=toIdx(*key);    
        
        if(nxt==-1) {
            bool ret=false; 
            for(int i=0; i<26;++i){
                if(alpha[i]!=NULL) ret=ret||(alpha[i]->search(key+1));
            }
            return ret; 
        }
        else {
            if(alpha[nxt]==NULL) return false; 
            return alpha[nxt]->search(key+1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */