const int MAX=987654321; 
class Solution {
public:
    vector<int> cost;
    vector<int> cache; 
    int day[3] = {1,7, 30};
    int n; 
    int MinCost(vector<int>& days, int idx){
        if(idx==n) return 0; 
        int start = days[idx]; 

        int &ret=cache[idx];
        if(ret!=-1) return ret; 
        ret=MAX; 
           
        for(int d=0; d<3; ++d){
            int nxt_idx = idx; 
            while( (nxt_idx<n) && days[nxt_idx] < day[d]+start){
                ++nxt_idx; 
            }
            ret=min(ret,cost[d] + MinCost(days, nxt_idx)); 
        }
           
        return ret;
           
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        cost.assign(costs.begin(), costs.end()); 
        
        n=days.size(); 
        cache.assign(n, -1);
        return MinCost(days,0);
        
    }
};