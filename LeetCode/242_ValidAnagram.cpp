class Solution {
public:
    int cnt[26];
    bool isAnagram(string s, string t) {
        memset(cnt, 0, sizeof(cnt));
        
        for(char c: s) cnt[c-'a']++; 
        
        for(char c: t){
            if( --cnt[c-'a'] < 0) return false;
        }
        
        for(int i=0; i<26; ++i){
            if(cnt[i]>0) return false; 
        }
        return true; 
    }
};
