#include <unordered_map> 
#include <queue> 
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        
        for(char c: s) m[c]++;
        
        priority_queue<pair<int,char>> pq; 
        for(auto it= m.begin(); it!=m.end(); ++it){
            pq.push({(*it).second, (*it).first});
        }
        string ans="";
        while(!pq.empty()){
            auto now =pq.top(); pq.pop();
            for(int i=0; i<now.first; ++i){
                ans+=now.second; 
            }
        }
        return ans; 
        
    }
};