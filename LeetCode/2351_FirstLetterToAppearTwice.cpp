#include <set> 
class Solution {
public:
    char repeatedCharacter(string s) {
        set<char> alpha_set; 
        for(char c: s){
            if(alpha_set.find(c) !=alpha_set.end() ) return c; 
            alpha_set.insert(c); 
        }
        return '0'; 
    }
};