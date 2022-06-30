#include <algorithm>
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(), ransomNote.end()); 
        sort(magazine.begin(), magazine.end());   
        auto cmpit = ransomNote.begin();
        auto it = magazine.begin();
        while( it!= magazine.end() && cmpit!=ransomNote.end()){
            if( *it == *cmpit) {
                ++it; 
                ++cmpit;
            }
            else ++it;
        }
        if( cmpit != ransomNote.end() ) return false; 
        return true;
    }
};