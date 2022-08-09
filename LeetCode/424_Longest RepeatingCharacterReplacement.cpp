const int MAX=987654321;
class Solution {
public:
    int term; 
    
    int characterReplacement(string s, int k) {
        return characterReplacement1(s,k);
        // return characterReplacement2(s,k);
    }
    
    int characterReplacement1(string s, int k) {
        term = k; 
        return charReplace(s);
    }
    
    int characterReplacement2(string s, int k) {
        term = k;
        int max_len=0;
        map<char,int> m; 
        
        for(char c: s) m[c]++; 
        for(auto it=m.begin(); it!=m.end(); ++it){
            char target=(*it).first;
            int part = charReplace(s, target); 

            max_len = max(max_len, part);
        }
        return max_len;
    }
    
    int charReplace(string &word, char target) {
         
        int left = term; 
        int s = 0, max_len=term; 
        
        
        for(int e=0; e<word.size(); ++e){
            
            if(word[e] == target); 
            else  --left;
            
            if(left<0) {
                while(s<=e){ 
                    if(word[s] != target) ++left;
                    ++s;
                    if(left>=0) break;
                }
            }
            
            max_len=max(max_len, (e-s+1));
            // cout <<word[e]<<" s="<<s<<" e="<<e<<" max_LEN="<<max_len<<endl; 
            
        }
        return max_len; 
    }    
    
    
    int charReplace(string &word) {
         
        int left = term; 
        int s = 0, max_len=term; 

        map<char, int> smap;
        for(char x='A'; x<='Z';++x) smap[x]=0; 
        
        map<char, int> left_map; 
        for(char x='A'; x<='Z';++x) left_map[x]=left; 
        
        
        for(int e=0; e<word.size(); ++e){
            
            for(auto it=left_map.begin(); it!=left_map.end(); ++it){
                char target = (*it).first; 
                
                if(target == word[e]); 
                else left_map[target]--; 
                
                if(left_map[target] < 0){
                    while(smap[target]<=e){
                        if(word[smap[target]]!=target) ++left_map[target];
                        ++smap[target];
                        if(left_map[target]>=0) break; 
                    }
                }
                max_len=max(max_len, e-smap[target]+1);
            }
            
        }
        return max_len; 
    }
};