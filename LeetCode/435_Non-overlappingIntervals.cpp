# include <algorithm>
# include <queue>

const int MIN=-987654321;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(); 
        priority_queue<pair<int,int>,deque<pair<int,int>>,greater<pair<int,int>>> pq; //(end,start)
 
        int bf_end = MIN;
        for(auto interval :intervals){
            pq.push({interval[1],interval[0]});
        }
        
        int included=0; 
        while(!pq.empty()){
            auto now = pq.top(); 
            pq.pop();
            
            if(now.second < bf_end) continue; 
            else {
                bf_end = now.first; 
                ++included;
            }
        }
        
        
        return n-included; 
    }
};