class Solution {
public:
    
    vector<vector<int>> pdrome;
    bool IsPdrome(string &word, int s, int e ){
        if(s==e) return true;
        if(s+1==e) return (word[s]==word[e]);
        
        if(s>e) return false; 
        
        int &ret=pdrome[s][e];
        if(ret!=-1) return ret; 
    
 
        if(word[s]!=word[e]) return false;
        bool part = IsPdrome(word, s+1,e-1);
        
        return ret=part;  
        
    }
    int countSubstrings(string s) {
        //포함관계 
        pdrome.assign(s.size(), vector<int>(s.size(),-1));
        
        int cnt=0; 
        for(int start=0; start<s.size(); ++start){
            
            for(int end=start; end<s.size(); ++end){
                if(IsPdrome(s,start,end)) ++cnt; 
            }    
        }
        
        return cnt; 
        
    }
};