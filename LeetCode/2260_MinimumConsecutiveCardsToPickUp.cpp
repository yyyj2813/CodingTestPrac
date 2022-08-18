#include <unordered_map> 
const int MAX=987654321;
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> m; 
        int min_val=MAX; 
        
        for(int i=0; i<cards.size(); ++i){
            if(m[cards[i]]==0) {
                m[cards[i]]=i+1; 
                continue; 
            }
            int cand= (i+1)-m[cards[i]]+1; 
            min_val=min(min_val, cand); 
            
            m[cards[i]]=i+1;      
        }
        
        if(min_val==MAX)return -1; 
        return min_val; 
    }
};