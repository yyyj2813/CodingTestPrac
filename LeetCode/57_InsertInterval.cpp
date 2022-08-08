#include <algorithm>
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        auto it= intervals.begin();
        for(;it!=intervals.end();){
            auto & now = (*it);
            if(now[1]<newInterval[0]) {
                ++it; 
                continue;
            }
            
            if(newInterval[1]<now[0]) break; 
            
            newInterval[0] = min(newInterval[0], (*it)[0]);
            newInterval[1] = max(newInterval[1], (*it)[1]);
            
            it=intervals.erase(it);    
        }
        
        intervals.insert(it, newInterval);
        
        return intervals; 
        
    }
};