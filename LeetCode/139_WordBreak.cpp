class Solution {
public:
    int cache[300]; 
    int Matches(string &s, string &cand, int idx){
        if(idx+cand.size() > s.size()) return -1; 
        
        for(int i=0; i<cand.size(); ++i){
            if(s[idx+i]!=cand[i]) return -1;    
        }
        
        return cand.size(); 
    }
    
    bool CanBreak(string &s, vector<string>& wordDict, int idx){
        if(idx == s.size()) return true; 
        else if(idx> s.size()) return false;
        
        int &ret= cache[idx];
        if(ret!=-1) return ret; 
        
        
        ret = 0; 
        for(string &cand: wordDict){
            int r = Matches(s,cand, idx);
            if(r == -1) continue; 
            ret = ret || CanBreak(s, wordDict, idx+r);
        }
        return ret; 
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(cache, -1, sizeof(cache));
        
        
        return CanBreak(s, wordDict, 0);
    }
};