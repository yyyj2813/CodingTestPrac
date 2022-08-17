#include <unordered_map> 
#include <queue> 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int > m;
        for(int n: nums) m[n]++;
        
        priority_queue<pair<int,int>,deque<pair<int,int>>,less<pair<int,int>>> pq; 
        for(auto it= m.begin(); it!=m.end(); ++it) {
            pq.push({(*it).second,(*it).first});
        }
        vector<int> ans;
        while(k>0){
            ans.push_back(pq.top().second);
            pq.pop(); 
            --k;
        }

        return ans;
        
        
    }
};