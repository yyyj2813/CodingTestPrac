#include <vector> 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total=1; 
        int zidx=-1; 
        int zcnt=0; 
        for(int i=0; i<nums.size(); ++i){
            int &n = nums[i];
            if(n==0){
                ++zcnt;
                zidx=i; 
                continue; 
            }
            total*=n; 
        }
        
        vector<int> ret(nums.size(),0);
        
        
        if(zcnt==0){
            for(int i=0; i<nums.size(); ++i){
                ret[i]=total/nums[i];
            }
            return ret; 
        }
        else if(zcnt==1){
            ret[zidx]=total;
            return ret; 
        }
        else return ret;    
        
    }
};