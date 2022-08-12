#include <unordered_map> 
const int MAX=987654321;
class Solution {
public:
    vector<int> GetMaxFeqNum(unordered_map<int,int> &cnt_map){
        int max_val=0; 
        vector<int> freq_nums;
        for(auto it =cnt_map.begin(); it!=cnt_map.end(); ++it){
            max_val=max(max_val, (*it).second);
        }
        
        for(auto it =cnt_map.begin(); it!=cnt_map.end(); ++it){
            if((*it).second==max_val) freq_nums.push_back((*it).first);
        }
        return freq_nums; 
    }
    int GetShortestLen(vector<int>& keys, unordered_map<int,int>&smap, unordered_map<int,int>& emap ){
        int ret=MAX; 
        for(int key:keys){
            int sidx= smap[key];
            int eidx = emap[key];
            ret=min(ret, eidx-sidx+1);
        }
        return ret; 
    }
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> cnt_map; 
        unordered_map<int,int> start_idx_map; 
        unordered_map<int,int> end_idx_map; 
        
        for(int i=0; i<nums.size(); ++i){
            int now= nums[i];

            cnt_map[now]++; 
            if(start_idx_map.find(now) == start_idx_map.end()) start_idx_map[now]=i; 
            end_idx_map[now]=i;
        }
        
        auto keys=GetMaxFeqNum(cnt_map);
        return GetShortestLen(keys, start_idx_map, end_idx_map);
        
        
    }
};