class Solution {
public:
    int n;
    bool DP(vector<int> &cache, vector<int>& nums, int idx){
        if(idx == n-1) return true; 
        else if(idx >= n) return false; 
        
        int & ret= cache[idx];
        if(ret!=-1) return ret; 
        
        int jump = nums[idx];
        
        
        for(int i=1; i<=jump; ++i){
            bool r= DP(cache, nums, idx+i); 
            if(r) return true; 
        }
        
        return ret = 0; 
    }
    
    bool canJump(vector<int>& nums) {
        n= nums.size(); 
        vector<int> cache(n, -1);
        return DP(cache, nums, 0);
    }
};