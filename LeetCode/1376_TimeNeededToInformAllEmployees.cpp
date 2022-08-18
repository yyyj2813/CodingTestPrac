#include <queue> 
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n, vector<int>()); //[a][b]: a의 부하직원 b
        for(int idx=0; idx<manager.size(); ++idx){
            int midx= manager[idx];
            if(midx==-1) continue; 
            graph[midx].push_back(idx); 
        }
        
        vector<bool> visited(n, false);\
        
        priority_queue<pair<int,int>, deque<pair<int,int>>, greater<pair<int,int>> > pq; //{time, idx}
        pq.push({0,headID}); 
        visited[headID]=true; 
        int time=0; 
        
        while(!pq.empty()){
            auto now =pq.top(); 
            pq.pop(); 
            time=now.first; 
            // cout<<time<<endl;
            
            for(int subord: graph[now.second]){
                if(visited[subord]) continue;
                visited[subord]=true; 
                pq.push({ time+informTime[now.second] , subord});
            }
        }
        return time; 

    }
};