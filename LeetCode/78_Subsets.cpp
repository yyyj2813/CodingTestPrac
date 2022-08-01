class Solution {
public:
    void DP(vector<vector<int>>& subvec, vector<int>& nums, int idx, vector<int> & ps){
        if(idx == nums.size()) {
            subvec.push_back(ps);
            return;
        }
        
        DP(subvec, nums, idx+1, ps);
        
        ps.push_back(nums[idx]);
        DP(subvec, nums, idx+1, ps);
        ps.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subvec = {}; 
        vector<int> v; 
        
        DP(subvec, nums, 0, v);
        return subvec; 
    }
};