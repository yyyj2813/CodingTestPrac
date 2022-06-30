
#include <unordered_map> 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) { 
        if(nums.size() == 0) return 0; 

        unordered_map<int,int> m; //key, val key부터 몇 개 이어져 있나 
        int max_length = 1; 
        
        for(auto n: nums){
            if(m[n]!=0) continue; //이미 값이 있었음
            
            m[n]=1;
            
            if(m[n+1] != 0 ) {
                m[n] = m[n+1]+1;
                max_length = max(m[n],max_length);
            }
            
            if(m[n-1] != 0 ){
                int idx= n-1; 
                while(m[idx]!=0){
                    m[idx] = m[idx+1]+1;
                    --idx; 
                }
                max_length = max(m[idx+1], max_length);
            }
        }
        
        return max_length; 
    }
};