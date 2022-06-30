class Solution {
public:
    int cache[100];
    int DP(vector<int>& nums, int idx){
        if(idx >= nums.size()) return 0; 
        
        int &ret = cache[idx];
        if(ret!=-1) return ret; 

        return ret= max( nums[idx]+DP(nums,idx+2) , DP(nums,idx+1));
        
    }
    
    int rob(vector<int>& nums) {
        memset(cache, -1, sizeof(cache));
        return DP(nums, 0);
    }
};