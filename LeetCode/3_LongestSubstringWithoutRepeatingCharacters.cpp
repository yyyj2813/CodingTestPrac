#include <unordered_map> 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m; 
        
        int sidx=0; 
        int max_len=0; 
        
        for(int i=0; i<s.size(); ++i){
            if(m.find(s[i])!=m.end()){
                sidx = max(sidx,m[s[i]] + 1);
            }
            m[s[i]] = i; 
            
            max_len = max(i-sidx+1, max_len);
        }    
        return max_len; 
    }
    
};