#include <algorithm> 
class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n =edges.size(); 
        vector<long long> score(n, 0); 
        for(int idx=0; idx<edges.size(); ++idx){
            score[edges[idx]] += idx; 
        }
        
        long long max_val=0;
        int mnode=0; 
        
        for(int node=0; node<n; ++node){
            if(max_val<score[node]){
                max_val=score[node]; 
                mnode=node; 
            }
        }
        return mnode; 
    }
};