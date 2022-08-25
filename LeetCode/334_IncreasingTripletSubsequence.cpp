#include <algorithm> 
class Solution {
public:
    bool increasingTriplet(vector<int> & nums) {
        vector<int> ans;
        ans.push_back(nums[0]); 
        
        for(int i=1; i<nums.size();++i){
            if(ans.back()<nums[i]) {
                ans.push_back(nums[i]); 
                if(ans.size()>=3) return true; 
            }
            else {
                auto it = lower_bound(ans.begin(), ans.end(), nums[i]); 
                *it= nums[i];
            }
        }
        return false; 
    }
};