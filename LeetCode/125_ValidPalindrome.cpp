#include <cmath> 
class Solution {
public:
    bool isPalindrome(string s) {
        for(auto it =s.begin(); it!=s.end(); ){
            if(!isalpha(*it) &&!isdigit(*it) ){
                it = s.erase(it);    
                continue; 
            }
            *it = tolower(*it);
            ++it; 
        }
        
        for(int i=0; i<s.size()/2; ++i){
            if(s[i]!=s[s.size()-1-i])   return false;   
        }
        return true; 
    }
};