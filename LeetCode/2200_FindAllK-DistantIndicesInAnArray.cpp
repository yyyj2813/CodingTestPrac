#include <set> 
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> s; 
        for(int j=0;j<nums.size();++j){
            if(nums[j]!=key) continue; 
            
            for(int idx= max(0, j-k); idx <= min(j+k , (int)nums.size()-1); ++idx){
               s.insert(idx); 
            }
        }
        
        vector<int> ans; 
        for(int n: s) ans.push_back(n); 
        
        return ans; 
        
    }
};