class Solution {
public:
    bool IsPalindrome(string &word){
        int d = (word.size())/2; 
        for(int i=0 ;i<d;++i){
            if(word[i]==word[word.size()-1-i]) continue;
            return false; 
        }
        return true; 
    }
    string firstPalindrome(vector<string>& words) {
        for(string &word:words){
            if(IsPalindrome(word)) return word; 
        }
        return "";
    }
};