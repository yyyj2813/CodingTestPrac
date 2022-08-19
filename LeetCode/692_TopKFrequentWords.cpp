#include <unordered_map> 
#include <queue> 
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m; 
        for(string w: words) m[w]++; 
        
        priority_queue<pair<int,string>, deque<pair<int,string>>, greater<pair<int,string>>> pq; 
        // priority_queue<pair<int,string>> pq; 
        
        for(auto it=m.begin(); it!=m.end(); ++it){
            pq.push( {-(*it).second, (*it).first} ); 
        }
        
        vector<string> ans; 
        while(k>0 && !pq.empty()){
            auto now = pq.top(); 
            pq.pop();
            
            ans.push_back(now.second); 
            --k; 
        }
        return ans; 
    }
};