#include <algorithm> 
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        special.insert(special.begin(), bottom-1); 
        special.push_back(top+1);
        
        sort(special.begin(), special.end()); 
        
        int max_wo_relax=0; 
        int s= special[0]; 
        for(int i=1; i<special.size(); ++i){
            max_wo_relax=max(max_wo_relax, (special[i]-s-1)); 
            s=special[i];
        }
        return max_wo_relax; 
    }
};
    