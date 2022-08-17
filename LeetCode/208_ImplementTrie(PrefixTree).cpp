const int alphabet=26;
class Trie {
public:
    bool terminal;
    Trie * children[26];
    
    Trie():terminal(false) {
        memset(children, 0, sizeof(children));
    }
    ~Trie(){
        for(int i=0; i<26;++i){
            if(children[i]) delete children[i];
        }    
    }
    
    int toNumber(char ch){
        return ch-'a';
    }
    void insert(string word) {
        insert(&word[0]);
    }
    bool search(string word) {
        return search(&word[0]);
    }
    bool startsWith(string prefix) {
        return startsWith(&prefix[0]);
    }
    
    void insert(char * key) {
        if(*key==0) {
            terminal = true; 
            return; 
        }
        int nxt= toNumber(*key);
        
        if(children[nxt]==NULL) {
            children[nxt] = new Trie();
        }
        children[nxt]->insert(key+1);
    }
    
    bool search(char * key) {
        if(*key==0){
            return terminal; 
        }
        int nxt= toNumber(*key);
        if(children[nxt]==NULL) return false;
        return children[nxt]->search(key+1);
    }
    

    bool startsWith(char *key ) {
        if(*key == 0) return true; 
        int nxt= toNumber(*key);
        if(children[nxt] == NULL) return false;
        return children[nxt]->startsWith(key+1);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */