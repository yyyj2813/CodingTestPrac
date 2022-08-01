const int MIN=-987654321; 
class Solution {
public:
    int n; 
    vector<int> cache; 
    
    int DP(vector<int>& nums, int bfv, int idx){
        if(idx == nums.size()) return 0; 
                
        int &ret = cache[idx]; 
        if(ret!=-1) return ret; 
        
        ret=0; 
        
        for(int i=idx; i<nums.size(); ++i){
            if(nums[i]<=bfv) continue;     
            ret=max(ret, 1 + DP(nums, nums[i], i+1));
        }
        
        return ret; 
    }
    
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        
        cache.assign(n, -1);
        
        
        return DP(nums, MIN, 0);
    }
};