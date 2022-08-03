#include <unordered_map>
class Solution {
public:
    unordered_map<int, int> m; 
    
    int DP(vector<int>& nums, int cost){
        if(cost == 0) return 1; 
        if(cost<0) return 0; 
        
        if(m.find(cost) != m.end()) return m[cost];
        int & ret= m[cost];
        ret=0; 
        
        for(int i=0; i<nums.size(); ++i){
            ret += DP(nums, cost-nums[i]);
        }
        return ret; 
    }
    
    
    int combinationSum4(vector<int>& nums, int target) {
        return DP(nums,target);
    }
};