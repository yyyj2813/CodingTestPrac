#include <stack> 
#include <unordered_map> 
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m;//unordered하니 speedup

        m.insert({')','('});
        m.insert({'}','{'});
        m.insert({']','['});
        
        stack<char> st; 
        for(char c: s){
            if( !st.empty() && m[c]==st.top()){
                st.pop(); 
            }
            else st.push(c);
        }
        if(st.empty()) return true; 
        return false; 
    }
};