class Solution {
public:
    vector<int> cache; 
    int DP(string &word, int idx){
        if(idx > word.size()) return 0; 
        if(idx == word.size() ) return 1;
        
        int &ret=cache[idx];
        if(ret!=-1) return ret; 
        ret=0; 
        
        if(word[idx]!='0'){
             ret += DP(word, idx+1);   
        }
        
        if(idx<word.size()-1){
            string part = word.substr(idx, 2);
            int sub = stoi(part);

            if(10<=sub && sub<=26) ret += DP(word, idx+2);
        }
        
        return ret; 
        
    }
    
    
    int numDecodings(string s) {
        cache.assign(s.size(), -1);
        return DP(s,0);
    }
};