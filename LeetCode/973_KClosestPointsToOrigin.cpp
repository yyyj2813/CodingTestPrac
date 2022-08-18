#include <queue>
typedef pair<long long , pair<int,int> > Data; 
class Solution {
public:
    long long CalcDist(long long x, long long y){
        return x*x+y*y; 
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Data, deque<Data>, greater<Data>>pq; 
        for(auto point : points){
            auto d = CalcDist(point[0], point[1]);
            pq.push({d, {point[0],point[1]} }); 
        }
        vector<vector<int>> ans; 
        
        while(k>0){
            auto now =pq.top(); 
            vector<int> tmp={now.second.first, now.second.second}; 
            ans.push_back(tmp); 
            
            pq.pop();    
            --k; 
        }
        return ans; 
        
    }
};